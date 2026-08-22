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
         ek array hai , aur ek number k 
         hame array a ko k subsequence me todna hai 
         
         contigious 

         such that 

         minimum of mex of all the subarrays is maximized 


  -> Your Attacks:
         what would be the value for k 
         like 1,n

         what would be the maximum value for the mex
         for all the subarrays , 
         which is nothing but the mex of whole 
         let M 

         so the maximum of the mex of all the 
         subarray is atmost M (not more than this , 
         jaruri nhi ki yahi ho isse kam bhi ho sakta hai right ? )

         then what is the problem ? 

         k is the problem ?

         how to divide into k segments ? 


         i have an idea

         check how many zeroes are there in the subarray 
         since we have to focus on maximizing the minimum 
         we have to maximize it 

        if the no of zero is less than k then 
        answer is 0 
        otherwize we have to proceed further 
        like if the number of zero is greater or equal to k , we have to proceed for that 

        mujhe ye to samajh aa rha hai ki un zero ke aas
        paas se construction karni hai , like 
        check for 1 , 2,3 ... 
        but kaise kru ? 

        se we have k subarray , so we try to find 
        atleast k zero 
        then the remaining elements is n-k 
        so we try to make all the subarrays mex
        equal to mex of whole array which is the maximum mex ? right ? 

        we have k zeroes , and y=n-k elements left 

        ab hamare pass do problems hai , ki ham kause zero choose kre ? like if zero >=k 

        kyuki zero ke position se hi ptachal jayega 
        ki mex kaise banega like locaiton of zero

        let us suppose k=3
        
       (1) 0  (2)  0  (3)  0 (4)
       there will be 4 
       positions for them 
       how to choose positions such a way 
       that min mex is maximized  
       or maximized all the mex 

       ;)
       use binary search 
       suppose t is the minimum mex 
       for k seqments 
       if t is possible , increase the t 
       if not , decrease the t

       how to check for t 

       i will create a string rrrrr of t length 
       and for each elmenents in a[i] let a[i]=0
       i will update string as rrrrrl
       and check if this equal to llllll or not 
       if it is equal , i found one segment
       where mex is t
       similarly i will try to find how many segmenets are there 
       if the segments are greater than k then its a yes 
       other wize its a no 


  -> Hints From Code:

*/
bool f(vector<int>a,int n,int mid, int  k ){
 vector<int>freq(mid,0);
  int seg=0;
  int dis=0;
  for(int i=0;i<n;i++){
    if(a[i]<mid){
      if(freq[a[i]]==0)dis++;
      freq[a[i]]++;
    }
   if(dis==mid){
    seg++;
    dis=0;
    fill(freq.begin(),freq.end(),0LL);
   }
    if(seg>=k)return true;
  }
  return false;



}
void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n,k;cin>>n>>k;
    vi a(n);invec(a);
    int l=0,h=n+2;
    while(l<=h){
      int m=(l+h)/2;
      if(f(a,n,m ,k)){
        l=m+1;
      }
      else h=m-1;
    }
    cout<<h<<endl;
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