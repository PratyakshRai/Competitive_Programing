/*
    Author: Pratyaksh Rai
    Date: 2026-05-31
    Time: 16:58:43
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
         do what we have to do , 

         for each range update the range , get the sum of its digit

         how to solve this problem 

         for those who are single digit , we dont bother anything 


         mai kya karne ki sooch rha hu
          har ek element ko step by step  unit digit me convert kar dunga 
          by summing up their digits 
          and save them 

          like ill make 2d vector for it 
          now i have to think for a particular range how to change
          the value for them 
          like i have a 2d vector where the values are the sum of digits 
          like 
          1 420 69 1434 2023
          1 6 15 12 7 
          1 6 6 3 7 

          like this 

          now i have to figure it out , how to answer the querry  ?
          i will make index array  for it 
          
          but the problem is that how should i update the indices of the 
          range ? 
          like if i take prefix sum of indixes
          like +1 at l and -1 at r+1 
          but i have to take prefix sum all the time 
          but only after the range of updation 
          but note once it hit the maximum thing liek 
          all the digits will have the unit digit only 
          it will stopp
          and i dont think it will take much time complexity 
          like 
          for largest number 999999999 firt step will take to 81 and then to 9 
          this thing is to be notices , rigth, for any number , it will take only two step , atleast under the constraints for the question 
          iska matlab ye hai ki 
          hame teesare baar se jade prefix sum nikalne ki jarurat hi nhi hai 
          right ? 
  -> Your Attacks:
         

  -> Hints From Code:

*/
void f(vector<int>&a,vector<vector<int>>&b,int i){
  int x=a[i];if(x<10)return ;
  while(x>=10){
    int res=0;
    int temp=x;
    while(temp>0){
      res+=temp%10;
      temp/=10;
    }
    b[i].pb(res);
    x=res;
  }
}int get_digit_sum(int x) {
    int sum = 0;
    while(x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n , q;cin>>n>>q;
    vi a(n);invec(a);
    set<int>act;
    for(int i=0;i<n;i++)if(a[i]>9)act.insert(i);
    while(q--){
      int type;cin>>type;
      if(type==1){
        int l, r;cin>>l>>r;
        l--;r--;
        auto it =act.lower_bound(l);
        while(it!=act.end()&&*it<=r){
          a[*it]=get_digit_sum(a[*it]);
          int idx=*it;
          it++;
          if(a[idx]<10)act.erase(idx);
        }
        
      }
      else {
        int x; cin>>x;
        cout<<a[--x]<<endl;
        
      }
    }







    // int n, q ;cin>>n>>q;
    // vector<int>a(n);invec(a);
    // vector<vector<int>>b(n);
    // vector<int>pre(n+2,0);

    // for(int i=0;i<n;i++)b[i].pb(a[i]);
    // for(int i=0;i<n;i++){
    // f(a,b,i);
    // }
    // int cnt=0;
    // vector<int>crr(n+2);
    // while(q--){
    //   int type;cin>>type;
    // if(type==1){
    //   int l,r;cin>>l>>r;
    //   l--;r--;
    //   crr[l]+=1;
    //   crr[r+1]-=1;

    // }else{
    //   int x;cin>>x;x--;
    //   int acc=0;
    //   for(int i=0;i<n;i++){
    //     acc+=crr[i];
    //     pre[i]+=acc;
    //     crr[i]=0;

    //   }
    //   crr[n]=0;
    //   crr[n+1]=0;
    //   cout<<b[x][min((int)b[x].size()-1,pre[x])]<<endl;
    // }
    // }
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