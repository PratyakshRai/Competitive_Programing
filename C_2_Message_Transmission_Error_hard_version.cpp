/*
    Author: Pratyaksh Rai
    Date: 2026-07-25
    Time: 20:12:46
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
         

  -> Your Attacks:
         

  -> Hints From Code:

*/
//code gemini ka hai ;*)

//knuth algo iski ma ka bhosda 
void Chal_Ja_Plz() {
    string s; 
    cin >> s;
    int n = s.size();
    
    if (n <= 1) {
        NO; 
        return;
    }
    
    vector<int> lps(n, 0); 
    
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1]; 
        
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1]; 
        }
        
        if (s[i] == s[j]) {
            j++;
        }
        
        lps[i] = j;
    }
    
    int overlap_length = lps[n - 1];
    
    if (overlap_length > 0 && (overlap_length * 2) > n) {
        YES;
        for (int i = 0; i < overlap_length; i++) {
            cout << s[i];
        }
        cout << endl;
    } else {
        NO;
    }
}
// void Chal_Ja_Plz() {
//     string s; cin >> s;
//     int n = s.size();
//     if(n == 1) {
//         NO; return;
//     }
    
//     int pos = n - 1;
//     int cnt = -1;
//     bool flag = false;
//     int index = -1;
//     int i = n - 2;
    
  
//     int best_len_A = -1;
//     int best_index = -1;
    
//     while(i >= 0) {
//         if(flag == false) {
//             if(s[i] != s[pos]) {
//                 i--; continue;
//             }
//             if(s[i] == s[pos]) {
//                 cnt = pos - i - 1;
//                 pos--;
//                 flag = true;
//                 index = i;
                
//                 // IF WE FIND A MATCH
//                 if(cnt == 0) {
//                     int len_B = n - 1 - index;
//                     int len_A = n - 2 * len_B;
                    
                   
//                     if(len_A > 0 && s.substr(0, len_A + len_B) == s.substr(len_B, len_A + len_B)) {
//                         best_len_A = len_A;
//                         best_index = index;
//                     }
                    
                 
//                     cnt = -1;
//                     pos = n - 1;
//                     flag = false;
//                     i = index - 1; 
//                     index = -1;
//                     continue;
//                 }
//                 i--;
//             }
//         }
//         else {
//             if(s[i] != s[pos]) {
//                 cnt = -1;
//                 pos = n - 1;
//                 flag = false;
//                 i = index - 1; 
//                 index = -1;
//             } else {
//                 cnt--;
//                 if(cnt == 0) {
//                     int len_B = n - 1 - index;
//                     int len_A = n - 2 * len_B;
                    
//                     if(len_A > 0 && s.substr(0, len_A + len_B) == s.substr(len_B, len_A + len_B)) {
//                         best_len_A = len_A;
//                         best_index = index;
//                     }
                    
//                     cnt = -1;
//                     pos = n - 1;
//                     flag = false;
//                     i = index - 1; 
//                     index = -1;
//                     continue;
//                 }
//                 pos--;
//                 i--;
//             }
//         }
//     }
    
//     if(best_len_A == -1) {
//         NO;
//     } 
//     else {
//         YES;
//         for(int j = 0; j <= best_index; j++) cout << s[j];
//         cout << endl;
//     }
// }
// void Chal_Ja_Plz() {
//     // There is always a simpler solution for the question 
//     string s;cin>>s;
//     int n=s.size();
//     if(n==1){
//       NO;return ;
//     }
//    int pos=n-1;
//    int cnt=-1;
//    bool flag=false;
//    int index=-1;
//    int gg=n-1;
//    int i=n-2;
   
//    while(i>=0){
//       if(flag==false){
//         if(s[i]!=s[pos]){i--;gg--;continue;}
//         if(s[i]==s[pos]){
//           cnt=pos-i-1;
//           pos--;
//           flag=true;
//           index=i;
//           gg--;
//           if(cnt==0)break;i--;
//         }
//       }
//       else{
//         if(s[i]!=s[pos]){
//           cnt=-1;
//           pos=n-1;
//           flag=false;
//           i=index-1;
//           index=-1;
//         }else {
//           cnt--;
//           gg--;
//           if(cnt==0){
//             break;
//           }
//           pos--;
//           i--;
//         }
        
//       }

//       // if(s[i]==s[pos]&&flag==false){
//       //   index=i;
//       //  cnt=pos-i-1;
//       //  flag=true;
//       //  pos--;
//       //  if(cnt==0){
         
//       //     break;
//       //   }
//       //   i--;continue;
//       // }
//       // else if (flag==true){
//       //   if(s[i]==s[pos]){cnt--;pos--;
//       //   if(cnt==0){
         
//       //     break;
//       //   }
//       //  i--;continue;
//       // }
//       //   if(s[i]!=s[pos]) {
//       //     flag=false;
//       //     cnt=-1;
//       //     pos=n-1;
//       //     index=-1;
//       //     continue;
//       //   }
//       // }
//       // i--;
//     }
//     int len_B = n - 1 - index;
//     int len_A = n - 2 * len_B;
//     if(len_A==0||index==-1||cnt!=0){NO;}
//     else {
//       YES;
      
//       for(int i=0;i<=index;i++)cout<<s[i];
//     }
//     cout<<endl;
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
    
    int t; t=1;
    while (t--) Chal_Ja_Plz();
    
    return 0;
}
/*
Three golden rules: 
1. Every problem has a solution 
2. Every problem has a simpler solution 
3. Understand what the problem is pointing to 
*/