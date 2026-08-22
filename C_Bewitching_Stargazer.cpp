 /*
     Author: Pratyaksh Rai
     Date: 2026-04-05
     Time: 14:04:31
 */
 
 #include <bits/stdc++.h>
 using namespace std;
 
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
          n starts in the sky 
          arranged in a row  

 
   -> Your Attacks:
          
 
   -> Hints From Code:
 
 */
//  void cal(int& ans ,int l,int r, int k){
//   if(r-l+1<k)return ;
//   int len=r-l+1;
//   int m=(r+l)/2;
//   if(len&1){
//     ans+=m;
//     cal(ans,l,m-1,k);
//     cal(ans,m+1,r,k);
//   }
//   else {
//     cal(ans,l,m,k);
//     cal(ans,m+1,r,k);
//   }
//   return ;
//  }
pair<int,int>cal(int len, int k ){
  if(len<k)return {0,0};
  pair<int,int>sub=cal(len/2,k);
  int c=sub.ff;
  int s=sub.ss;
  if(len&1){
    int mid=(len+1)/2;
    return {2*c+1,2*s+c*mid+mid};

  }
  else {
    int mid=len/2;
    return {2*c,2*s+c*mid};
  }
}
 void Chal_Ja_Plz() {
     // There is always a simpler solution for the question 
     int n,k;cin>>n>>k;
     int ans=0;
    cout<<cal(n,k).ss<<endl;
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