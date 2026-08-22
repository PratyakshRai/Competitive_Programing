/*
    Author: Pratyaksh Rai
    Date: 2026-06-04
    Time: 18:28:11
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
         here what is the thing, like if the astronought has power less 
         than the humanoid 
         it can be directly absorbed 

         then thing is when in becomes complex ? 
         how to use blue and green serum nicely ? 
         there is two  2x and one 3x 
         then thing is 3x , then 2x 2x is better than 
         2x 2x then 3x ? 
         like 3x ke baad 2x 2x jade fayda de rha hai but har ek case me nhi ? 
         also 2x 3x 2x is also benefitial 

         okay the final condition is 
         agar ek 2x se nhi ho rha hai 
         to phir 3x se dekho
         if then also not possible 
         then see 2x 2x 
         then after 2x && 3x 
         if also not then 
         then 2x 2x 3x 
         its like 
         like increasing series of multiplier will be 
         2x 
         3x 
         2x 2x 
         2x 3x
         2x 2x 3x  , right ?  
         ai=1 walo par multiplier waste nhi karna hai ? right ? 
         

  -> Your Attacks:
         

  -> Hints From Code:

*/
int dp(vector<int>&a,int i,int g,int b,int h){
  if(i==a.size())return 0;
  if(a[i]<h)return dp(a,i+1,g,b,h+a[i]/2)+1;
  int ans1=g?dp(a,i,g-1,b,2*h):0;
  int ans2=b?dp(a,i,g,b-1,3*h):0;
  return max(ans1,ans2);
}
void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n , h;cin>>n>>h;;
    vi a(n);invec(a);
    srt(a);
    cout<<dp(a,0,2,1,h)<<endl;

    // int g=2,b=1;
    // int ans=0;
    // int i=0;
    // while(i<n){

    //   int t=a[i++];
    //   if(t==1){
    //     ans++;continue;
    //   }
    //   if(t<h){
    //     ans++;
    //     h+=t/2;
    //   }
    //   //  2x 
    //   //    3x 
    //   //    2x 2x 
    //   //    2x 3x
    //   //    2x 2x 3x
    //   else {
    //     if(g>0&&2*h>t){
    //       ans++;
    //       g--;
    //       h*=2;h+=t/2;
    //     }
    //     else if(b>0&&3*h>t){
    //       ans++;
    //       b--;
    //       h*=3;h+=t/2;
    //     }else if (g>1&&4*h>t){
    //       ans++;
    //       g-=2;h*=4;h+=t/2;
    //     }
    //     else if(g>0&&b>0&&6*h>t){
    //       ans++;
    //       g--;b--;h*=6;h+=t/2;
    //     }else if(g>1&&b>0&&12*h>t){
    //       ans++;
    //       g=0;b=0;h*=12;h+=t/2;
    //     }else {
    //       break;
    //     }

       
    //   }
    // }
    // cout<<ans<<endl;
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