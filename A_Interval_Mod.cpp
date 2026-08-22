/*
    Author: Pratyaksh Rai
    Date: 2026-06-24
    Time: 10:30:03
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
         what i can do is to give each number their type, right ? 
         let focus on single elememt 
         put p>=q
         if i can attain by only %p then it is of type 1
         if %q then of type 2 , if %pthen %q then it is of type 3
         
         then we have the type of array as 

         1 1 1 1 2 2 2 3 3 2 3 1 1 
         we can select the whole segment 
         but if not 
         then we have to select atleast k length 
         which may contains different types 
         like 2 2 3 1 2 3 
         we have to check type of modulo over them is good   , right ? 

         we can use common type , like if the number is divisible by both 

         ohh , to ek baar agar koi apne minimum stage me challa gya to chahe uspe aage jake type 1 operation lage ,ya type 2 uska minimum minimum hi rhega,,,to ham pahale wo array length k ka choose karenge ,jiski penalty sabse kam ho , ek baar k length select ho gyi to ham phir us segment ke left aur right me ek ek karke expand krenge aur pure array ko cover karne ka try karenge , right ? 


  -> Your Attacks:
         

  -> Hints From Code:

*/

  void Chal_Ja_Plz() {
      // There is always a simpler solution for the question 
      int n, k,p,q;cin>>n>>k>>p>>q;
      vi a(n);invec(a);
      int best=0;
      vi type1(n),type2(n);

      for(int i=0;i<n;i++){
        type1[i]=a[i]%p;
        type2[i]=(a[i]%q)%p;
        best+=min(type1[i],type2[i]);
        int t=min(type1[i],type2[i]);
        type1[i]-=t;
        type2[i]-=t;
      }
      int mn=INF;
      int A=0,B=0;
      for(int i=0;i<n;i++){
        A+=type1[i];B+=type2[i];
        if(i>=k){
          A-=type1[i-k];B-=type2[i-k];
        }
        if(i>=k-1){
          mn=min({mn,A,B});
        }
      }
      cout<<best+mn<<endl;;
    //   vi type(n);
    //   if(q>p)swap(p,q);
      
    //   for(int i=0;i<n;i++){
    //     if(a[i]%p==0||a[i]%q==0){
    //       continue;
    //     }
    //     ans+=min({a[i]%p,a[i]%q,(a[i]%p)%q,(a[i]%q)%p});
    //   }
    //   if(p==q){
    //     cout<<ans<<endl;return;
    //   }
    //   for(int i=0;i<n;i++){
    //     int x=a[i];
    //     if(x%p==0&&x%q==0){
    //       type[i]=4;
    //     }else if(x%p==0){
    //       type[i]=1;
    //     }else if (x%q==0){
    //       type[i]=2;
    //     }else {
    //       int y=(x%p)%q;
    //       if(y==x%p)type[i]=1;
    //       else if(y==y%p)type[i]=2;
    //       else type[i]=3;
    //     }
    //   }
    //   vi pre(n+1);
    //   for(int i=0;i<n;i++){
    //     pre[i+1]=a[i]+pre[i];
    //   }
    // ans=0;
    // int bck=-1;
    
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