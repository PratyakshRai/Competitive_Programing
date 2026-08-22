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
         so we have to do the procedures K times 

         so agar array pahale mex ke form me hai 
          like 
          0 1 2 3 4 5 6 7 

          to koi bhi operation karlo , 
        array same hi hoge right? 

    but If not then what ? 

    : ? 

    can we say after a full lenght operation 
    array will become a full mex like 0 1 2 3 4 .. typo thing 
    so we have to just see 
    if k is less than n ? right  ? 

    us element ko hta hi de rha hai 
    

    okay , so  i am wrong , 
    i wrongly interpreted the question 
    cheeje simultaneously ho rhi hai  

    but but ek baar full mex aa gya to wah hi rhe ga hamesha 
    so atleast ek baar full iteration karna padega ,

    let say  current mex m hai 
    ab ek element m se bda hai , to usko m likh denge 
    ab ek element m se chhota hai , to uski frequency 
    dekhenge agar frequency 1 hai to no change , otherwise m likhdenge 

    is tarah ham first iteration karenge  , right ? 

    agar mex == length of array hai to no change , just sum up all elements 

    k=1 , k=2 ,k=3 
    k=2 se cheeje repeat karne lagengi ? right ? 
    k=2 pr jo hai wahi 4 pe , 6 pe .... 
    k=3 pr jo hai wahi 5 pe 7 pr 
  -> Your Attacks:
         

  -> Hints From Code:

*/
int mex(vector<int>&a){
  int n=a.size();
  set<int>st;
  for(int i=0;i<n;i++){
    st.insert(a[i]);
  }
  for(int i=0;i<=n;i++){
    if(st.size()==0){
      return i;
    }
    auto it =st.begin();
    int val=*it;
    st.erase(it);
    if(val!=i){
      return i;
    }
  }
  return n;
}
void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n,k;cin>>n>>k;
    vi a(n);invec(a);
    int mx=mex(a);
    vector<int>freq(n+1);
    for(int i=0;i<n;i++)freq[a[i]]++;
    for(int i=0;i<n;i++){
      if(a[i]>mx)a[i]=mx;
      else if (a[i]<mx){
        if(freq[a[i]]>1)a[i]=mx;
        
      }
    }
    int ans=0;
    ans=accumulate(a.begin(),a.end(),0LL);
    if(k==1){
      cout<<ans<<endl;
      return;
    }
    mx=mex(a);
    freq.assign(n, 0);
     for(int i=0;i<n;i++)freq[a[i]]++;
     for(int i=0;i<n;i++){
      if(a[i]>mx)a[i]=mx;
      else if (a[i]<mx){
        if(freq[a[i]]>1)a[i]=mx;
        
      }
    }
    int even=0;
     ans=accumulate(a.begin(),a.end(),0LL);
     even=ans;
     if(k==2){
      cout<<ans<<endl;
      return;
    }
    int odd=0;
     mx=mex(a);
    freq.assign(n, 0);
     for(int i=0;i<n;i++)freq[a[i]]++;
     for(int i=0;i<n;i++){
      if(a[i]>mx)a[i]=mx;
      else if (a[i]<mx){
        if(freq[a[i]]>1)a[i]=mx;
        
      }
    }
     ans=accumulate(a.begin(),a.end(),0LL);
     odd=ans;
     if(k==3){
      cout<<ans<<endl;
      return;
    }
    if(k%2==0){
      cout<<even<<endl;return;
    }
    cout<<odd<<endl;
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