/*
    Author: Pratyaksh Rai
    Date: 2026-08-24
    Time: 00:39:26
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
Three golden rules: 
1. Every problem has a solution 
2. Every problem has a simpler solution 
3. Understand what the problem is pointing to 
*/
/*
  -> Small Observations:
        what we want is  
        f(s) will equal to k or not 
        like kya hame sirf k consecutive mill sakta hai ki nhi ?   
        
        means hame us m length ki window me k log infected chahiye, right ? 

        we cannot use sliding window to iterate it  , right ?  as r is very large, rigth ? 


        we want exactly k , right ? 

        m me k ko rangna hai , aur bakiyo ko nhi rangna hai, right ?

  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
/*
    ** Cases Ko Generalize karne ki koshish kro
    ** Agar 15 min me idea kaam nhi kar rha ya jade 
       sara test case ban rha hai to 
       APPROACH BADLO
    ** MIN/MAX me ek baar Binary Search sochna agar 
       current idea kaam nhi kar rha to     
*/

    int n, m,k;cin>>n>>m>>k;

    vector<pair<int,int>>lr;
   vector<int>r,l,dis;
   int op=0;
   for(int i=0;i<n;i++)
   {
    int L,R;cin>>L>>R;
    lr.push_back({L,R});
    op+=R-L+1;
    dis.pb(op);
    r.pb(R);
    l.pb(L);
   }

    if (k == 0) {
        cout << r[n-1] + 1 << endl;
        return;
    }

    auto get = [&](int x){
        if(x<1)return 0LL;
        int t=x;
        auto j=upper_bound(l.begin(),l.end(),t);
        if(j==l.begin()){
            return 0LL;
        }
        
        int idx=j-l.begin();
        idx--;
        int ans=(idx>0)?dis[idx-1]:0;
        ans+=max(0LL,min(r[idx],t)-l[idx]+1);
        return ans;

    };
    auto p=[&](int x)->int {
        return get(x+m-1)-get(x-1);
    };
int low=0;
int val=0;
    for(int i=0;i<n;i++){
        if(val<p(l[i])){
            low=l[i];
            val=p(l[i]);
        }
    }
    if(val==k){
        cout<<low<<endl;
        return ;
    }
    if(k>val){
        
        cout<<-1<<endl;
        return;     
    }
    int high=1e18;
    while(high - low > 1){
        int mid=low+(high-low)/2;
        if(p(mid)>k){
            low=mid;
        }
        else if(p(mid)<k) {
            high=mid;
        }
        else {
            cout<<mid<<endl;
            return ;
        }
        

    }
    cout<<-1<<endl;;



//     auto get_pos = [&](int req) {
//         if (req == 0) return 0LL;
//         int idx = lower_bound(dis.begin(), dis.end(), req) - dis.begin();
//         int extra_inside = dis[idx] - req;
//         return r[idx] - extra_inside; // Exact position jahan req complete hota hai
//     };
// for(int i = 0; i < n; i++) {
       
//         int s = l[i];
//         int e = s + m - 1;
        
      
//         int C = get_pref(e) - get_pref(s - 1); 

//         if (C == k) {
//             cout << s << endl; return;
//         }

      
//         if (C > k) {
//             int infectedtillnow = (i > 0) ? dis[i-1] : 0;
            
         
//             int req_e = infectedtillnow + k; 
            
//             int new_e = get_pos(req_e); 
//             int s_new = new_e - m + 1;  
            
           
//             int limit = (i > 0) ? r[i-1] + 1 : 1;
//             if (s_new >= limit && s_new <= l[i]) {
//                 cout << s_new << endl;
//                 return;
//             }
//         }

        
//         int s_right = r[i];
//         int e_right = s_right + m - 1;
//         int C_right = get_pref(e_right) - get_pref(s_right - 1);

//         if (C_right <= k && k <= C) { 
//             int low = l[i], high = r[i];
//             while(low <= high) {
//                 int mid = low + (high - low) / 2;
//                 int val = get_pref(mid + m - 1) - get_pref(mid - 1);
//                 if (val == k) { cout << mid << endl; return; }
//                 if (val > k) low = mid + 1;
//                 else high = mid - 1;
//             }
//         }
//     }

   
}

//    for(int i=0;i<n;i++){
//     int currenctLeft=l[i];
//     int infectedtillnow=0;
//     if(i>=1)infectedtillnow=dis[i-1];
//     int infectionReq=infectedtillnow+k;
//     auto it = lower_bound(dis.begin(), dis.end(),infectionReq);

// if (it != dis.end() ) {
//    int  idx=it-dis.begin();
//    int extra=dis[idx]-infectionReq;
//    int t=0;if(i>0){t=l[i]-r[i-1]-1;}else{t=l[i]-1;}


//     if(t>=extra){
//         cout<<l[i]-extra<<endl;
//        return ;
//     }

// } else {
//    cout<<-1<<endl;
//    return;
// }
//    }

//        cout<<-1<<endl;
//        return;                 
    


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
