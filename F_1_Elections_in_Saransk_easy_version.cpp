/*
    Author: Pratyaksh Rai
    Date: 2026-06-22
    Time: 10:31:42
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
         so lcm(a,b,c,d)=a*b*c*d
         it is only possible if a, b, c, d are coprime to each other 
         right ? 

          okay lets say we got the divisors for each ai 
          but what can i do for the divisors ? 
          how should i proceed after this ?
          the question is can i able to proceed after this ? 
          lets see
          let for the first number we choose one of the divisors 
          then for the second no we have to choose that divisors ,which will have gcd with privious one =1 then for the third numebr 
          we have to choose that divisor which has gcd with all the pair on the left =1 which is i think not possible ? right ? 
          can i do dp here ,no, because if i choose gcd =1 with one elment on the left , there might me case where he got gcd with other element !=1 , like 8 9 4 ,where 8 , 9 , 4 are the divisors of a1, a2, a3, right 
          gcd(8,9)=1,gcd(9,4)=1,but gcd(8,4)!=1, right ? 

          so what we should do , how to overcome this problem ? 

          okay if we make map of the divisors , like 
          2  kitno ko divide kar rha  hai ,
          3 || || || || ||
          4 || || || || || || 
          no i think i have to choose the prime numbers only ,right ?
          like 
          2 3 5 7 
          like 2 kitno ko divide kar rha hai , similarly 3 then 5 , then 7 and so on 
          
          now how to move forward after this ? 

          okay if i pick let say 3 ,now i have to choose for the 
          others , the divisors ? if not possible for a number to choose divisor , i can choose 1 for him  right ? 
          now say if i choose 3 
          and i am now at the 2 like 2 kitno do divide kar sarta hai 
          ye pta hai, to ab ham combination kaise nikale ? 

  -> Your Attacks:
         

  -> Hints From Code:

*/
const int MM=5e5+10;
vector<int>no(MM);
vector<int>pr(MM,1);

void si(){
  pr[0]=pr[1]=0;
  no[1]=1;
  for (int i = 1; i < MM; i++) {
        no[i] = i; 
    }
  for(int i=2;i*i<=MM;i++){
    if(pr[i]){
      no[i]=i;
      for(int j=i*i;j<=MM;j+=i){
        pr[j]=0;
        no[j]=i;
      }
    }
  }
}
void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n,x;cin>>n>>x;
    vi a(n);invec(a);
    map<int,int>mp;
    for(int i:a){
      int temp=i;
      
      while(temp>1){
        mp[no[temp]]++;
        temp/=no[temp];
      }
    }
    int ans=1;
    for(auto it :mp){ans*=(it.ss+1);ans=ans%MOD;}
    cout<<ans<<endl;
    
}

// ========================================================================
//                             MAIN FUNCTION
// ========================================================================
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    si();
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