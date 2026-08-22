/*
    Author: Pratyaksh Rai
    Date: 2026-06-21
    Time: 18:25:43
*/

#include <bits/stdc++.h>
using namespace std;

// ========================================================================
//                         PBDS (ORDERED SET) SETUP
// ========================================================================
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// 1. UNIQUE SET
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;

// 2. SAFE MULTISET (For duplicates, insert as {value, index})
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

/* --- QUICK MANUAL ---
 * bag.order_of_key(k)    -> Count of elements strictly smaller than 'k'.
 * *bag.find_by_order(k)  -> Value at k-th position (0-indexed). 
 * [Note: Use (*bag.find_by_order(k)).first for multiset]
 */

// ========================================================================
//                              MACROS & TYPES
// ========================================================================
#define int             long long
#define pb              push_back
#define all(x)          (x).begin(), (x).end()
#define endl            '\n'
#define YES             cout << "YES\n"
#define NO              cout << "NO\n"
#define vi              vector<int>
#define vp              vector<bool>
#define ff              first
#define ss              second
#define setbits(x)      __builtin_popcountll(x)
#define clz(x)          __builtin_clzll(x)
#define ctz(x)          __builtin_ctzll(x)
#define gcd(a, b)       __gcd(a, b)
#define lcm(a, b)       (1ll*(a) * (b / gcd(a, b)))
#define invec(v)        for(int &i : v) cin >> i;
#define srt(v)          sort((v).begin(), (v).end())
#define rsrt(v)         sort((v).rbegin(), (v).rend())

// ========================================================================
//                         CONSTANTS & DIRECTIONS
// ========================================================================
const int INF = 1e18;
const int MOD = 1e9 + 7;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dx8[8] = {1, -1, 0, 0, 1, 1, -1, -1}; // Down, Up, Right, Left, D-R, D-L, U-R, U-L
int dy8[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// ========================================================================
//                         DEBUGGING & CUSTOM STRUCTS
// ========================================================================
#define printv(v)       for(auto x : v) cout << x << " "; cout << endl;
#define printmap(m)     for(auto x : m) cout << x.ff << " " << x.ss << endl;

// Custom sort for pairs
bool customsort(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.ff == b.ff) return a.ss < b.ss;
    return a.ff > b.ff;
}

// Anti-Hack Custom Hash for unordered_map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
}; // Use: unordered_map<int, int, custom_hash> safe_map;

// ========================================================================
//                         MATH & NUMBER THEORY
// ========================================================================
// 1. Safe Square Root
int sqr(int n) { int r=sqrtl(n); while((r+1)*(r+1)<=n)r++; while(r*r>n)r--; return r; }

// 2. Fast Power modulo
int binpow(int a, int b, int m = MOD) {
    int res = 1; a %= m;
    while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; }
    return res; 
}

// 3. Sieve of Eratosthenes (Call sieve() in main if needed)
const int MAX_PRIME = 1e6 + 5;
bool is__prime[MAX_PRIME];
vi _prime;
void sieve() {
    memset(is__prime, true, sizeof(is__prime)); is__prime[0] = is__prime[1] = false;
    for(int i=2; i*i<MAX_PRIME; i++) if(is__prime[i]) for(int j=i*i; j<MAX_PRIME; j+=i) is__prime[j] = false;
    for(int i=2; i<MAX_PRIME; i++) if(is__prime[i]) _prime.pb(i);
}

// 4. Combinatorics (Call precompute_factorials() in main if needed)
const int MAXF = 2e5 + 5;
int fact[MAXF], invfact[MAXF];
int modInverse(int n) { return binpow(n, MOD - 2); }
void precompute_factorials() {
    fact[0] = 1; invfact[0] = 1;
    for(int i=1; i<MAXF; i++) fact[i] = (fact[i-1] * i) % MOD;
    invfact[MAXF-1] = modInverse(fact[MAXF-1]);
    for(int i=MAXF-2; i>=1; i--) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
}
int nCr(int n, int r) {
    if(r < 0 || r > n) return 0; 
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

// ========================================================================
//                            PROBLEM LOGIC
// ========================================================================
/*
  -> Small Observations:
         so the thing is ki alice ko bhi contigious chahiye,  
         so we have to think for some prefix and suffix , aur unke beech ka bachha hua 
         alice khayegi isnt it ? 
         kyuki m monster ko jab hame khana dena hai , to ham part part me karke nhi de sakte like 
         if 1 1 10 1 1 10 1 1 10 is there 
         and 3 moster of bhukh 2 is there 
         we cant do 1 1 , 1 1 , 1 1 ,for all three monsters ,right ? 
         
         then there will be some cases right 

        case 1: yato prefix se hi sara  khilado aur end ka alice ko dedo , 
        case 2:  yato suffix se hi sara khilado monster ko aur starting ka alice ko dedo  

        case 3: yato kuchh prefix aur kuchh suffix se 
         khilao aur bich ka alice ko dedo ,right ?
         
         case 1 and case 2 is pretty much clear 

         but how to do it with case three ? 
         that is the problem 

         i think i got it 

         so there will be two pointer , one prefix sum and one suffix sum 

         let monster ki bhukh is x 
         we will search for element >=x
         after the pointer , right ? 
         for both the prefix and the suffix , 
         and then we will see where is less loss 
         like let say we got p from prefix 
         and s from suffix 
         so we will see min(p , s)
         and increase that pointer , from that side 
         right ? 
         note p or s >=x right , if we failed to get both p<x and s<x and output -1 , 
         right ? 

         nah bruh we have to check all the possible combinations right 
         kyuki min choose karne ke chhakkar me 
         aage ka future bigad sakta hai , right? 
         we dont know the future , right ? 


  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n , m, v;cin>>n>>m>>v;
    vector<int>a(n+1);
    vector<int>presum(n+2,0);
    for(int i=1;i<=n;i++){
      cin>>a[i];
      presum[i]=presum[i-1]+a[i];
    }
    vector<int>left(m+1,n+1);
    vector<int>right(m+1,n+1);
    left[0]=0;
    right[0]=n+1;
    int curr=0,mos=0;
    for(int i=1;i<=n&&mos<m;i++){
      curr+=a[i];
      if(curr>=v){
        curr=0;
        mos++;
        left[mos]=i;
      }
    }
    if(mos<m){
      cout<<"-1\n";return;
    }
    curr=0,mos=0;
    for(int i=n;i>=1&&mos<m;i--){
      curr+=a[i];
      if(curr>=v){
        mos++;
        right[mos]=i;
        curr=0;
      }
    }
    int ans=0;
    for(int i=0;i<=m;i++){
      int l=left[i];
      int r=right[m-i];
      if(l<r){
        int sum=presum[r-1]-presum[l];
        ans=max(ans,sum);
      }
    }
    cout<<ans<<endl;
}

// ========================================================================
//                             MAIN FUNCTION
// ========================================================================
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // Uncomment below lines if problem requires precomputation
    // sieve(); 
    // precompute_factorials();
    
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    
    return 0;
}
/*
Three golden rules: 
1. Every problem has a solution 
2. Every problem has a simpler solution 
3. Understand what the problem is pointing to 
*/