/*
    Author: Pratyaksh Rai
    Date: 2026-06-11
    Time: 17:43:09
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
         so acutally we want to maximize the minimum distance after putting all the k teleports 


         so what we have , 
         let d is the distance between  two consecutive  friend ,
         let a friend is at 4 and the consecutive friend is at 
         9
         hence 
         4: 5 6 7 8 :9 
         we will alway put the teliporter in the middle
         right 

         agar even length hai to do consecutive teliporter rakhunga ek sath (check karlunga ki teliporters ka number enough hai bhi ki nhi ) agar ek hi teliporter bachha hai to kisi bhi ek par 
         rakh dunga , right 

         agar odd length rha tb ? 
         4: 5 6 7 :8
         to bs beech me rakh dunga 
         0 par koi nhi hoga to usko special distance me daal dunga , 
         similarly end wale point pe koi nhi hua to usko bhi special point pe rakh dunga  

  -> Your Attacks:
         

  -> Hints From Code:

*/
bool check (int d, vector<int>a ,int x , int k){
  if(d==0)return true;
  int coverkiya=0;
  int curl=-1,curr=-1;
  for(int pos:a){
    int l=max(0LL,pos-d+1);
    int r=min(x,pos+d-1);
  
    if(curr==-1){
      curl=l;
      curr=r;
    }else{
      if(l<=curr+1)curr=max(curr,r);
      else {
        coverkiya+=curr-curl+1;
        curl=l;
        curr=r;

      }
    }
  }
  {
    coverkiya+=curr-curl+1;
  }
  return (x+1-coverkiya)>=k;
}
void Chal_Ja_Plz(){
  int n, k, x;cin>>n>>k>>x;
  vi a(n);
  invec(a);
  srt(a);
  int low=0,high=x+1;
  int best=0;
  while(low<=high){
    int mid=(low+high)/2;
    if(check(mid, a, x, k)){
      best=mid;
      low=mid+1;
    }else high=mid-1;


  }
  vector<pair<int,int>>merged;
  if(best>0){
    int curl=-1, curr=-1;
    for(int pos:a){
      int l=max(0LL,pos-best+1);
      int r=min(x,pos+best-1);
      if(curr==-1){
        curl=l,curr=r;
      }else {
        if(l<=curr+1)curr=max(curr,r);
        else {
          merged.pb({curl,curr});
          curl=l;curr=r;

        }
      }
    }
    if(curr!=-1)merged.pb({curl,curr});
  }
  vi ans;
  int curr=0;
  int idx=0;
  while(ans.size()<k&&curr<=x){
    if(idx<merged.size()){
      if(curr<merged[idx].first){
        ans.pb(curr);
        curr++;
      }else {
        curr=merged[idx].second+1;
        idx++;
      }
    }else {
      ans.pb(curr);curr++;
    }

  }
for(int i:ans)cout<<i<<" ";cout<<endl;

}

// void Chal_Ja_Plz() {
//     // There is always a simpler solution for the question 
//     int n,k,x;cin>>n>>k>>x;
//     vi a(n);invec(a);
//     srt(a);
//     int sp0=-1,spx=-1;
//     if(a[0]!=0)sp0=a[0];
//     if(a[n-1]!=x)spx=a[n-1];
//     vi ans;
//    multiset<pair<int,pair<int,int>>> st;

// for(int i=0;i<n-1;i++){
//     st.insert({a[i+1]-a[i]-1, {a[i+1], a[i]}});
// }
//       while(k>0){
//         if(k==0)break;
//         if(!st.empty()){
//            auto it = prev(st.end());
//             int mn=max(sp0,spx);
//             int d=it->first;
//             if(d<mn){
//               if(sp0<spx){
//                 ans.pb(spx);
//                 spx--;
//               }else {
//                 ans.pb(sp0);
//                 sp0--;
//               }
//               k--;
//             }
//             else {
//               if(d==1){
                
//                 int f=it->ss.ff;
//                 ans.pb(f+1);
                
//                 int s=it->ss.ss;
//                 st.erase(it);
//                 st.insert({0,{f,f+1}});
//                 st.insert({0,{f+1,s}});k--;
//               }else if (d>1){
//                 if(d%2!=0){
//                   int loc=(d+1)/2;
//                    int f=it->ss.ff;
//                     int s=it->ss.ss;
//                    ans.pb(f+loc);
//                    st.erase(it);
//                 st.insert({d/2,{f,f+loc}});
//                 st.insert({d/2,{f+loc,s}});k--;
//                 }
//                 else {
//                   if(k>1){
//                      int f=it->ss.ff;
//                      ans.pb(f+d/2);
//                      ans.pb(f+d/2+1);
//                       int s=it->ss.ss;
//                       st.erase(it);
//                       st.insert({d/2-1,{f,f+d/2}});
//                      st.insert({d/2-1,{f+d/2+1,s}});
//                       k-=2;
//                   }else {
//                      int f=it->ss.ff;
//                     ans.pb(f+d/2);
//                     break;
//                   }
//                 }
//               }else if(d==0){
                
//                 for(int i=0;i<n&&k>0;i++){
//                   ans.pb(a[i]);k--;
//                 }
//                 break;
//               }
//             }

// // cout << it->first << endl;               
// // cout << it->second.first << endl;        
// // cout << it->second.second << endl;   

//       }
//     else {
//       if(sp0<spx){
//                 ans.pb(spx);
//                 spx--;
//               }else {
//                 ans.pb(sp0);
//                 sp0--;
//               }
//               k--;
//     }
    
//     }
//       for(int i:ans)cout<<i<<" ";
//       cout<<endl;
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