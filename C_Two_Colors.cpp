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
         n planks are there 
         same size 
         paint his fence 
         rules: 
         each plank of the fence will be painted in one color 
         matlab ek plank ko do color se paint nhi kar sakte ho 

         contigious painting honi chahiye  , like 
         yato safeed , phir kala  , yato kala phir safeed 
         safeed ke beech me kala nhi , kale ke beech me safeed nhi 


         mujhe ye to samajh me aa gya hai ki kya karna hai 
         like ek color uthao ax aur baki un color ay such that 
         ax+ay>=n ke saath combination likho 
         aur end me 2 se multiply kardo ? rigth ? 

         like 
         5 8 9 manlo ye hai 

         pahale 5 ko pick kiya 
         phir 12-5 =7 
         so >=7 wale elements liye 
         jo ki 8 aur 9 hai 
         
         ab 8+5-12 +1 =2 
         aur 9+5-12+1=3
         ab phir 8 ko pick kiya 
         12-8 =4 so element greater than 4 which is nothing but 9 
         so 9+8-12+1=6
         
         end me 9 bacha but koi aur hai hi nhi 

         so total 6+3+2 =11
         ans=11*2 =22 
         right ? 

         to calculate it fast , i will maitain a 
         suffix array , 
         for an elment let say x 
         ill find 12-x=y 
         >=y element in the array 
         let its found at ith position (0th indexing)
          then suffix array will give me the sum 
          let s 
          then what ill do is 
          s-(n-i)*12 +(n-i) this will give me the number of 
          cases , similarly ill do for every number of the array 





  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n,m;cin>>n>>m;
    vi a(m);
   for(int i=0;i<m;i++){
    cin>>a[i];
    a[i]=min(a[i],n-1);
   }
    sort(all(a));
    vi suffix(m);
    suffix[m-1]=a[m-1];
    for(int i=m-2;i>=0;i--)suffix[i]=a[i]+suffix[i+1];
    int ans=0;
    for(int i=0;i<m;i++){
      int y=n-a[i];
      auto it =lower_bound(a.begin()+i+1,a.end(),y);
      if(it!=a.end()){
        int index=it-a.begin();;
        ans+=suffix[index]-(m-index)*n+(m-index)+(m-index)*a[i];
      }
    }
    cout<<ans*2<<endl;
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