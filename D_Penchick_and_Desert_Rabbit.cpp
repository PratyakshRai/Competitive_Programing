/*
    Author: Pratyaksh Rai
    Date: 2026-07-14
    Time: 16:45:59
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
         aage jab bhi jayega to hamesha chhote pe hi kudega ? right? 
         aur pichhe jayega to apne se max pe kudega , right ? 
         

         pichhe se jo value aa rhi hai wo to shorted hai , ie , the maximum till now right ? , which prefix max , what ever
         now the case is 
         what about jumping forward  ? 


         kyu na mai pichhe se hi build kru, right ? 
         then i have to check how many elmenets are smaller than 5 and have largest value , right  ? 


         at the end mereko kya chahiye ,5 se chhota ho ,with the largest value how to find that element ? 

         the thing is it can be anything like 

         their might be case where 
         their like 
         a pair like (1,10) (2,5)
         or (1,5) (2,10 )then how should i check that ? 
         pichhe se bhi to aage ja sakta hai meri jaan ,what about that case mutherfucker ? 

         okay the case is check both the sides , right ? 

         sari problem wahi aake fas rhi hai ki mai age kis number pe kudau ki mujhe maximum mil jaye , 
         i can maitain a prefix max for that ,yes sir 

  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vi pre(n);
    vector<pair<int,int>>suf(n);
    pre[0]=a[0];
    for(int i=1;i<n;i++){
      pre[i]=max(pre[i-1],a[i]);
    }
    suf[n-1]={a[n-1],n-1};
    for(int i=n-2;i>=0;i--)
    {
      int val=suf[i+1].ff;
      int idx=suf[i+1].ss;
      if(val<=a[i]){
        suf[i]={suf[i+1].ff,suf[i+1].ss};
      }else {
        suf[i]={a[i],i};
      }
    }
    
    vi ans(n);
    ans[n-1]=pre[n-1];
    for(int i=n-2;i>=0;i--){
      ans[i]=pre[i];
      if(ans[i]>suf[i+1].ff){
        ans[i]=max(ans[i],ans[suf[i+1].ss]);
      }

    }
    for(int i:ans)cout<<i<<" ";cout<<endl;

    // int mx=-INF;
    // vi mxy(n+1);
    // for(int i=1;i<=n;i++){
    //   mxy[i]=max(mx,a[i]);
    //   mx=mxy[i];
    // }
    // // for(int i:mxy)cout<<i<<" ";
    // // cout<<endl;
    //  mx=-INF;
    // vector<int>ans(n+1);
    // map<int,pair<int,int>>mp;
    // for(int i=n;i>0;i-- ){
    //   auto it= mp.lower_bound(a[i]);
    //   int map_val=-INF;
    //   if(it!=mp.begin()){
    //     it--;
    //     map_val=it->second.ff;
    //   }
    //   ans[i]=max({map_val,mxy[i]});
    //   if(map_val!=-INF){
    //     ans[i]=max(ans[i],ans[it->second.ss]);
    //   }
    //   mp[a[i]]={ans[i],i};
    //   // if(map_val!=-INF){
    //   //   it->second=max(it->second,ans[i]);
    //   // }
    // }
    // mp.clear();
    // // for(int i=1;i<=n;i++){
    // //   mxy[i]=max(mx,ans[i]);
    // //   mx=mxy[i];
    // // }
    // // for(int i=n;i>0;i-- ){
    // //   auto it= mp.lower_bound(ans[i]);
    // //   int map_val=-INF;
    // //   if(it!=mp.begin()){
    // //     it--;
    // //     map_val=it->second;
    // //   }
    // //   ans[i]=max({map_val,mxy[i]});
    // //   mp[ans[i]]=ans[i];
    // //   // if(map_val!=-INF){
    // //   //   it->second=max(it->second,ans[i]);
    // //   // }
    // // }
    // for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    // cout<<endl;
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