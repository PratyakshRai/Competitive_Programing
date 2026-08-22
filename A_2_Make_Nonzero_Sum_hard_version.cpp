/*
    Author: Pratyaksh Rai
    Date: 2026-06-06
    Time: 17:06:46
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
         like hame partitioning karni hai 
         har partitioning me alternate sum lagta hai , rigth? 
         if possible ,then we have to output the length of the partitioning ? along with the index  

         so we will choose the simplest partioning , like 
         if the sum of whole array is zero , then we will 
         consider each element as a partioting 
         otherwize ham dekhenge ki array ka sum kya aa rha hai ,right

         consecutive ones and consecutive -ve ones ko ek saath segment bna diya okay , to unka alternative sum 
         yato 0 hoga ,yato 1 hoga for consecutive ones
         and for consecutive -1 it should be 0 or -1 
         

         then i will have a series where no two elements are equal , rigth
         then i will take the sum 
         and let say the sum is x , then
         i will check how many 0 1 or 0 -1 are there 
         if the sum is even then ans may be possible 
         if the sum is odd then it is not possible 



        //  then ill sum the consecutive ones and the zeros which are together  ,rigth  
        //  if 1 -1 or -1 1 then ill sum up them or make their pair and store them and remove them from the jhamela 
        //  then ill have either 
         
        //  0 1 
        //  0 -1 
        //  hame 1 0 , -1 0 se koi matlab nhi ye koi help nhi karne wale hai 
        //  agar sum x hai 
        //  to 0 x wale segment ka sum -x , right ? 
        //  then i will consider all those as separate , then calculate the total sum 
        //  if the sum is zero , then good ? right ? 
        //  if not , then either the sum is +ve or -ve
        //  then will check how many 0 1 
        //  0 -1 are there 



  -> Your Attacks:
         

  -> Hints From Code:

*/
void Chal_Ja_Plz() {
    int n; cin >> n;
    vi a(n); invec(a);
    
    int sum = 0;
    vector<pair<int, pair<int,int>>> nw;
    
    for(int i = 0; i < n; i++) {
        sum += a[i];
        nw.pb({a[i], {i + 1, i + 1}});
    }
    
    if(sum % 2 != 0){
        cout << -1 << endl;
        return;
    }
    
    int cnt = 0;
    
    for(int i = 0; i < (int)nw.size() - 1; i++){
        if(sum == 0) break;
        
        if(sum < 0){
          
            if(nw[i+1].ff == -1){
                sum += 2;
                nw[i+1].ss.ff = nw[i].ss.ff; 
                nw[i].ff = -100; 
                cnt++;
                i++; }
        } 
        else {
            
            if(nw[i+1].ff == 1){
                sum -= 2;
                nw[i+1].ss.ff = nw[i].ss.ff; 
                nw[i].ff = -100; 
                cnt++;
                i++;
            }
        }
    }
    
    if(sum != 0){
        cout << -1 << endl;
        return;
    }
    
    cout << nw.size() - cnt << endl;
    for(int i = 0; i < nw.size(); i++){
        if(nw[i].ff != -100){
            cout << nw[i].ss.ff << " " << nw[i].ss.ss << endl;
        }
    }
}

// void Chal_Ja_Plz() {
//     // There is always a simpler solution for the question 
//     int n;cin>>n;
//     vi a(n);invec(a);
//     vector<pair<int,int>>ans;
//     int sum=accumulate(a.begin(),a.end(),0LL);
//     if(sum==0){
//       cout<<n<<endl;
//       for(int i=1;i<=n;i++)cout<<i<<" "<<i<<endl;
//       return;
//     }
//     a.pb(-19);
//     vector<pair<int,pair<int,int>>>nw;
//     int last=0;
//     int value=-10;
//     for(int i=0;i<=n;i++){
//       int len=i-last;
//       if(a[i]==0){
//         if(value==-10){
//         nw.pb({(value==-10)?0:value,{last+1,i+1}});}
//         else {
//           if(len%2==0){
//             nw.pb({0,{last+1,i}});
//           }else {
//             nw.pb({(value==-1)?-1:1,{last+1,i}});
//           }
//           nw.pb({0,{i+1,i+1}});
//         }
//         value=-10;
//         last=i+1;
//       }else {
//         if(value==-10){
//           last=i;
//           value=a[i];
//         }else {
//           if(value!=a[i]){
//            if(len%2==0){
//             nw.pb({0,{last+1,i+1}});
//           }else {
//             nw.pb({(value==-1)?-1:1,{last+1,i+1}});
//           }
//             last=i;
//             value=a[i];
//           }
//         }
//       }
//     }
//     // nw[(nw.size()-1)].ss.ss-=1;
//     sum=0;
//     for(int i=0;i<nw.size();i++)sum+=nw[i].ff;
//     if(sum==0){
//       cout<<nw.size()<<endl;
//       for(int i=0;i<nw.size();i++)cout<<nw[i].ss.ff<<" "<<nw[i].ss.ss<<endl;
//       return;
//     }
//     int p=0, q=0;
//     for(int i=0;i<nw.size()-1;i++){
//       if(nw[i].ff==0&&nw[i+1].ff==1)p++;
//       if(nw[i].ff==0&&nw[i+1].ff==-1)q++;
//     }
//     if(sum%2!=0){
//       cout<<-1<<endl;return;
//     }
//     int cnt=0;
//      for(int i=0;i<nw.size()-1;i++){
//       if(sum==0)break;
//       if(sum<0){
//         if(nw[i].ff==0&&nw[i+1].ff==-1){
//           sum+=2;
//           nw[i+1].ss.ff-=1;
//           cnt++;
//           nw[i].ff=-100;
//         }
//       }else {
//         if(nw[i].ff==0&&nw[i+1].ff==1){
//           sum-=2;nw[i+1].ss.ff-=1;
//           nw[i].ff=-100;
//         }
//       }
//      }
//      if(sum!=0){
//       cout<<-1<<endl;
//       return;
//      }
//      cout<<nw.size()-cnt<<endl;
//      for(int i=0;i<nw.size();i++){
//       if(nw[i].ff!=-100){
//         cout<<nw[i].ss.ff<<" "<<nw[i].ss.ss<<endl;
//       }

//      }
//     // for(int i=0;i<nw.size();i++)cout<<nw[i].ff<<" ";
//     // cout<<endl;

    
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