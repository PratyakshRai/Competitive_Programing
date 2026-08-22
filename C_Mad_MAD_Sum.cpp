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
         so we get an array and an function MAd
         mad will gives us largest number from the array 
         which appears atleast twice 
         i no numeber appears twice , it gives zero 

         ab dekho array bhi change ho rhi hai 
         har iteration me array ka sum nikal rha hai aur sum me jud rha hai 
         let say ith operation hai ye 
         then phir usi operation  me 
         puri array change ho rhi hai  ? right ? 


         agar ham pahala iteration khud karde to phir array 
         transform hoke 
         0 2 2 2 3 3 3 4 4 ho jayega (let )
         phir is ke aage to sorted hai 
         suffix array ki help se har iteration me 
         sum calculate kar lenge ? right ? 

         no its not working 
         how should i cumulatively calculate the mad thing , that is the problem ? right ? 
         i dont want to calculate the array again and again 
         for each iteration , it there any solution for it ? 

         hey its like it is shifting towards the end 
         let 2 2 2 2 3 3 3 4 4 
         then in next iteration 
         0 2 2  2 2 3  3 3 4 

         similarly for 
         2 1 1 2 
         0 0 1 2 
         then in next iteration 
         it becomes zero ie 0 0 0 0 

         if we have 
         1 2 3 4 5 
         then in next iteration it becomes 0 
         this array will never shift rigth , it directly becomes 0 
         like 4 3 2 1 1 2 3 4 will yeild 0 0 0 0 1 2 3 4
         okay so we will make another level 
         like after getting the first array we will create another from it 
         now the second array will definitely have repeting element or 
         zero elements 
         1 1 1 2 2 2 3 3
         like this 
         now what will happen next 
         0 1 1 1 2 2 2 3 
         then next 
         0 0 1 1 1 2 2 2 
         then next .. and so on , as you can see 
         we can the right shift thing ? right? 
         
          

  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n;cin>>n;
    vi a(n);
    invec(a);
    set<int>st;
    map<int,int>mp;
    vi final(n);
    int ans=accumulate(a.begin(),a.end(),0LL);
    for(int i=0;i<n;i++){
     
      mp[a[i]]++;
      if(mp[a[i]]>=2)st.insert(a[i]);
      if(!st.empty()){
        final[i]=*st.rbegin();
      }
    }
    ans+=accumulate(final.begin(),final.end(),0LL);
    st.clear();mp.clear();
    vi f(n);
    for(int i=0;i<n;i++){
      mp[final[i]]++;
      if(mp[final[i]]>=2)st.insert(final[i]);
      if(!st.empty())f[i]=*st.rbegin();
    }
    int t=accumulate(f.begin(),f.end(),0LL);
    for(int i=n-1;i>=0;i--){
      ans+=t;
      t-=f[i];
    }
    // for(int i: f)cout<<i<<' ';
    cout<<ans;
    cout<<endl;










    // vi pre(n+1);
    // for(int i=n-1;i>=0;i--)pre[i]=pre[i+1]+final[i];
    // cout<<ans<<" ";
    // for(int i=0;i<n;i++){if(final[i]!=0){ans+=pre[i];cout<<pre[i]<<" ";}}
    // // for(auto it=1;it<n;it++)cout<<pre[it]<<" ";
    // cout<<ans<<endl;
    // // cout<<endl;
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