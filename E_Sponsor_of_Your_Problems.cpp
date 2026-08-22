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
         what do you mean by same length 
         decimal representatoin 

         what could be the maximum value
         for r-l
         ? 
         99999999-90000000
         9999999
         this is nothing but 10^7
         so we can do o(n) ? 


         it did gave tle , 
         10^9 * 10^4 (from testcase)
         

         can we do binary search on the answer ? 
         nope it is not monotonous ? right

         can we reduce the tc
  -> Your Attacks:
         i have to iterate only on the l and r thing 

         notice , from the msb if it is same in both 
         it must be counted , 
         where it is different , 
         we must do out analysis from there 
         right? 

         okay , i will first get r-l , 
         this will tell me how much i can add to a digit 
         i will add the minimum amount for each 
         digit to make it different from both 
         l and r 
         if they are equal then only i will add 
         also i will consider the 9 9 situation 
         i will first trim out the  equal positions 

  -> Hints From Code:

*/
int f(int l, int x){
  string L=to_string(l);
  string X=to_string(x);
  int ans=0;
  int n=L.size();
  for(int i=0;i<n;i++){
    if(L[i]==X[i])ans++;
  }
  return ans;
}

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int a,b;cin>>a>>b;
    int cnt=0;
    int res=0;
    while(a>0){
      cnt++;
      int add=1;
      if((a%10+1)%10==b%10){
        add++;
      }
      if(a+add<=b){
        res+=2;
        
      }
      else if ((a%10)==(b%10)){
        add=1;
        if(a+add<=b){
          res++;
          a+=add;
        }
      }else res++;
      a/=10;
      b/=10;
    }
    cout<<cnt*2-res<<endl;
    // string l,r;
    // cin>>l>>r;
    // if(l==r){
    //   cout<<2*(l.size())<<endl;
    //   return;
    // }

    // int ptr=0;
    // while(ptr<l.size()&&l[ptr]==r[ptr])ptr++;
    // if(l[ptr]+1<r[ptr]){
    //   cout<<2*ptr<<endl;;
    //   return;
    // }
    // int res=2*ptr+1;
    // for(int i=ptr+1;i<l.size();i++){
    //   if(l[i]=='9'&&r[i]=='0')res++;
    //   else break;
    // }
    // cout<<res<<endl;;

    // int l,r;cin>>l>>r;
    // // string L=to_string(l);
    // // string R=to_string(r);
    // int n=L.size();
    // int ans=0;
    // int idx=n;
    // for(int i=0;i<n;i++){
    //   if(L[i]!=R[i]){idx=i;break;}
    //   ans+=2;
    // }
    // int amount=r-l-1;
    // int carry=0;
    // int p=0;
    // for(int i=n-1;i>=idx;i--){
    //   int t=binpow(10,p++);
    //  if(((L[i]-'0')+carry)==R[i]-'0'){
    //   if(amount-1>=0){
    //     amount-=t;
    //     if((L[i]-'0')==9)carry=1;
    //     else carry=0;
    //   }
    //   else {
    //     ans+=i+1;
    //     break;
    //   }
    //  }
    //  else {
    //   int c=R[i]-'0';
    //   int v=L[i]-'0';
    //   int x=t;
    //   int  val=v;
    //   int cnt=10-v;
    //   while(amount>=0&&(val==c||val==v)){
    //     val++;
    //     cnt--;
    //     amount-=x;
        
    //   }
    //   if(cnt<=0)carry=1;
    //   if(val==c||val==v){
    //     ans+=i+1;break;
    //   }
    //  }
    // }
    // cout<<ans<<endl;


    // int ans=INF;
    // for(int i=l;i<=r;i++){
    //   int t=f(l,i);
    //   int g=f(i,r);
    //   ans=min(ans,t+g);
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