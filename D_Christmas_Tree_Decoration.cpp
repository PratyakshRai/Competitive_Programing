/*
    Author: Pratyaksh Rai
    Date: 2026-06-11
    Time: 10:31:04
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
const int MOD = 998244353;

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
         we have  n+1 decoration boxes , right ?
         initiaaly ith box contains ai decorations , right 

         we have n length permutation ,right ? 
         zeroth box is special , right ? 

         seperate the 0th box, like this 

         a0 | a1 a2 a3 a4 a5 , right  
         look at ai i!=0 , some boxes will have 0 value ,and some will have 1 or more values , right ? 

         how to calculate the number of fair permutation , right ? 
        achha permutation pi ki value maan lo x hai to wo x box se hi 
        value pick karega chahe wo kahi bhi rakha ho  , right ? 
        jis ai ki frequency jade hai unko aage rakho ,right ? 
        like 
        1| 2 1 0 ,here a1 ki frequency jade hai , to ise ham aage 
        rakhenge , right  
        ham ai ki values ko reduce kardenge , like 
        if 2 4 2 2 , hai man lo , to ek loop ke baad , chahe jo bhi mermutation ho , value, kya ho jayegi 
        1 3 1 1 ek aur permutation ke baad 0 2 0 0 

        let say we have 
        1 4 2 1 
        ek round ke baad value ho jayegi

        0 3 1 0 

        ab isme frequency ke hisaab se set kiya to 
        hoga 
        a2 a3 a1 a4 
        ab iske baad ye dekhna hai ki different permutation ka kya logic hai , right ?  
        now the thing is ye kaha tk utilize kar paa rha hai ,ye dekhna hai,right 
        jaise is case me a3 tk jake sab utilize ho rha hai,right 
        like 3 1 0 0 | 6
        2 0 0 0 |4 
        1 0 0 0|1
        0 ->0<- 0 0 |0
        
        yani last ke 3 zero ho mai kaise bhi rakh sakta hu  right ? 
        ab kyuki second position pe aake sari value khatam ho ja rhi hai to mai 

  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n;cin>>n;
   int a0;cin>>a0;
   vi a(n);invec(a);
   int total=accumulate(a.begin(),a.end(),0LL);
   total+=a0;
   int k=total/n;
   int b0=a0;
   int z=0;
   for(int i=0;i<n;i++){
    if(a[i]>=k){
      if(a[i]-k>1){
        cout<<0<<endl;
        return;
      }
      if(a[i]-k==0)z++;
      
    }
    else {
      b0-=k-a[i];
      z++;
    }
   }
   if(b0<0){
    cout<<0<<endl;return;
   }
   int x=z-b0;
  //  if(x<0||x>z){
  //   cout<<0<<endl;
  //   return;
  //  }
   int ans=nCr(z,x);
   ans=(ans*fact[x])%MOD;
   ans=(ans*fact[n-x])%MOD;
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
    precompute_factorials();
    
    int t; cin >> t;
    while (t--) {Chal_Ja_Plz();}
    
    return 0;
}
/*
Three golden rules: 
1. Every problem has a solution 
2. Every problem has a simpler solution 
3. Understand what the problem is pointing to 
*/