/*
    Author: Pratyaksh Rai
    Date: 2026-07-11
    Time: 20:18:05
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
         have to find all the divisors of all the number 
         first the case is if all the numbers within that range is same , we can say it is infinity 
         right ? 
        how should we check 
        we can make a track of distinct number at a particular index right ? 
        substract that range  , and check if it is equal to 
        zero or not , right ? 
        the next thing is we have to check the lest number within that range 
         precalculate all the numbers , right ? 
         like their divisors ? 

         what are the things that erritating you 
         case  1: 
         kya sare elements ka mod 0 bnana zaruri hai ? 


         jra soocho mod ki value kya ho sakti hai 
         bda number chhota hoga  , right  ? 
         aur jo m se chhota hai wo same rhega , right? 
         

         to jo m se chhote number hai wo sare same hone chahiye right  ? 

         if we take the least number from the range 
         can we make it as a remainder 
        



  -> Your Attacks:
         

  -> Hints From Code:

*/
// 
struct sparsetable{
  int n, k ;vector<vector<int>>st;
  vector<int>lg;
  sparsetable(const vector<int>&a){
    n=a.size();
    lg.assign(n+1,0);
    for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
    int k=lg[n];
    st.assign(k+1,vector<int>(n));
    for(int i=0;i<n;i++)st[0][i]=a[i];
    for(int j=1;j<=k;j++){
      for(int i=0;i+(1LL<<j)<=n;i++){
        st[j][i]=gcd(st[j-1][i],st[j-1][i+(1LL<<(j-1))]);
      }
    }
  }
  int query (int l, int r){
    int j=lg[r-l+1];
    return gcd(st[j][l],st[j][r-(1LL<<j)+1]);
  }
};
void Chal_Ja_Plz() {
int n,q;cin>>n>>q;
vi a(n);invec(a);
vi diff(n);
for(int i=0;i<n-1;i++){
  diff[i]=abs(a[i]-a[i+1]);
}
sparsetable sp(diff);
while(q--){
  int l, r;cin>>l>>r;
  l--;r--;
  if(l==r){
    cout<<0<<" ";
    continue;
  }
  cout<<sp.query(l,r-1)<<" ";
}
cout<<endl;


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
 
//  // root_n is the square root of INT_MAX ie root_n*root_n =INT_MAX 
//  // so if we take mid as root_n +2 , then mid*mid should overflow , right ?  
//  // for overfow ,   "if((a*a)%mod<a) then then overflow detected ? "
//  // we can use binary multiplication which will have the same answer as (a*a)%mod right ? , but let say we some how get (a*a)%mod 

  

//   // output : 147580950 2147483647 147483633
//   // "if for overflow we take  ((a*a)%mod>a) then we have a false case for it , ie (3 * 3 ) %mod >3 , but no over flow here 
//   // how u are detecting overflow using modulo 
  
// //.............
//   // if you take modulo as INT_MAX  
//   int m=INT_MAX;
//   long long  root_n=46340+2;
//   long long sq=root_n*root_n;
//   sq=sq%m;
//   int y=INT_MAX%m;
//   cout<<sq<<" "<<INT_MAX<<" "<<y<<endl;;

//   // output : 97317 2147483647 0
//   // again 97317>mid_value (46340+2), but here it is again overflow  
  
//    // mod =1e9+7
//   // third case  : " if  for overflow this condition holds true if((a*a)%mod  > INT_MAX%mod"
//   // y = INT_MAX%mod = 147483633
//   // mid = root of y ie root ie 147483633 = 12144 (12144.28.. more precise )
//   // so ((mid+1)*(mid+1))%mod >( INT_MAX%mod) right ? overflow conditioon holds true    

//   // but 12145² = 147,501,025(smaller that INT_MAX ) no overflow here 