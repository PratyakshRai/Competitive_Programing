/*
    Author: Pratyaksh Rai
    Date: 2026-07-04
    Time: 09:17:51
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
         what is the thing here,like 
         agar mai ek col dekhu ya phir ek row , then

         let say i have 3 3 
         then agar unke upar ya neeche me agar 
         difference 1 ka aagya to khel khatam , right ? 
         like 2 1 ya phir 1 2 , right ? mai tb higher wala option hi choose karunga , rigth 
         but agar dono aa gya ,2 1 aur 1 2 bhi to mai kuchh nhi kar sakta , right ? 
         now there is a third case ki agar , 
         ki dono me se koi ek bhi choose kar saku to  ? then unke left aur right me dekhna padega ki kahi +1 karne se bagal wale se koi match to nhi na ho rha hai ,if yes then dono me se kiske paas jade ka advantage , hai ,right ? its something like bridge , right ? 
         like agar 1 2 3 4 , hai to agar 1 ko badaya ,to 
         2 2 3 4 ho jayega, aur mujhe ultimately
         2 3 4 5, karna padega,right ? 

         kya koi aasan sa tarika nhi hai ? 

  -> Your Attacks:
         

  -> Hints From Code:

*/
  int fun(vector<vector<int>>&h,vector<int>a,int n){
    vector<vector<int>>dp(n,vector<int>(2,INF));
    dp[0][0]=0;
    dp[0][1]=a[0];
    for(int i=1;i<n;i++){
      // for(int x=0;x<=1;x++){
      //   for(int y=0;y<=1;y++){
      //   bool flag=true;
      //   for(int j=0;j<n;j++){
      //     flag&=(h[i-1][j]+y!=h[i][j]+x);
      //   }
      //   if(flag){
      //     if(x){
      //       dp[i][x]=min(dp[i][x],dp[i-1][0]+a[i]);
      //     }
      //     else {
      //       dp[i][x]=min(dp[i][x],dp[i-1][1]);
      //     }
      //   }
      // }
      // }
      bool flag=true;
      for(int j=0;j<n;j++){
        flag&=(h[i-1][j]!=h[i][j]);
      }
      if(flag){
        dp[i][0]=dp[i-1][0];
      }
      flag=true;
      for(int j=0;j<n;j++){
        flag&=(h[i-1][j]+1!=h[i][j]);
      }
      if(flag){
        dp[i][0]=min(dp[i][0],dp[i-1][1]);
      }
      flag=true;
       for(int j=0;j<n;j++){
        flag&=(h[i-1][j]!=h[i][j]+1);
      }
      if(flag){
        dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
      }
      flag=true;
      for(int j=0;j<n;j++){
        flag&=(h[i-1][j]+1!=h[i][j]+1);
      }
     if(flag) dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
    }
    return min (dp[n-1][0],dp[n-1][1] );
  }

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n;cin>>n;
    vector<vector<int>>h(n,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>h[i][j];
    vi a(n+1),b(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
   int total=0;
   total+=fun(h,a,n);
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++)swap(h[i][j],h[j][i]);
   }
   total+=fun(h,b,n);
   if(total>=INF)cout<<-1<<endl;
   else cout<<total<<endl;

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