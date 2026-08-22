/*
    Author: Pratyaksh Rai
    Date: 2026-07-23
    Time: 20:41:33
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
         end se dekhunga ki kitne element ka sum chhota hai b[m-1] se taki unme zero cost lage , right  
         let say we have the total sum 
         hey to somewhat it is to find the minimum cost to make >=sum using b array 
         but the thing is to somepoint  i cannot choose some element in b , right ? 
         its like we have parts 
         like 
         part A ||PartB|| PartC...
         in the last part we can use upto last element 
         in upcomming part we cant use some of the elements  , right ? 
         how to  solve this problem ? 

  -> Your Attacks:
         

  -> Hints From Code:

*/
int n,m;
int dp(int idx ,vector<int>&prefix,int j,vector<int>&b,vector<vector<int>> &memo){
  //base case maanlente hai 
  
  if(idx>n)return 0 ;
  if(j>=m)return INF;
  if(memo[idx][j]!=-1)return memo[idx][j];
  int ans=INF;
  
  int y=prefix[idx-1]+b[j];
  auto it=upper_bound(prefix.begin(),prefix.end(),y);
  int r=it-prefix.begin()-1;
  if(r>=idx){
    int cost=m-1-j;
    ans=min(ans,cost+dp(r+1,prefix,j,b,memo));
  }
  ans=min(ans,dp(idx,prefix,j+1LL,b,memo));
  return memo[idx][j]= ans;
}
void Chal_Ja_Plz() {
    int n, m;
    cin >> n >> m;
    
    vi a(n);
    invec(a);
    
    vi b(m);
    invec(b);
    
    vector<int> pref(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    
    // 1. Setup table with INF
    vector<vector<int>> dp(n + 2, vector<int>(m + 1, INF));

    // 2. Base Cases
    for (int j = 0; j <= m; j++) {
        dp[n + 1][j] = 0; // Array is fully cleared
    }
    // (dp[i][m] is already INF by default, so we don't need a loop for it)

    // 3. Fill the table BACKWARDS
    for (int i = n; i >= 1; i--) {
        for (int j = m - 1; j >= 0; j--) {
            
            // Option 1: Skip the current weapon
            dp[i][j] = dp[i][j + 1];

            // Option 2: Use the current weapon
            int target = b[j] + pref[i - 1]; 
            auto it = upper_bound(pref.begin() + i, pref.end(), target);
            int R = it - pref.begin() - 1;

            if (R >= i) {
                int cost = m - 1 - j;
                dp[i][j] = min(dp[i][j], dp[R + 1][j] + cost);
            }
        }
    }

    // Answer is stored at the starting state
    int ans = dp[1][0];
    
    // Print the final result!
    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
// void Chal_Ja_Plz() {
//     // There is always a simpler solution for the question 
//     cin>>n>>m;
//     vi a(n);invec(a);vi b(m);invec(b);
//     vector<int>pref(n+1);
//     for(int i=0;i<n;i++)pref[i+1]=pref[i]+a[i];
//     // vector<vector<int>> memo(n + 2, vector<int>(m + 1, -1));
//     // int t=dp(1LL,pref,0LL,b,memo);
//     // if(t!=INF){
//     //   cout<<t<<endl;
//     // }
//     // else cout<<-1<<endl;

// }

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