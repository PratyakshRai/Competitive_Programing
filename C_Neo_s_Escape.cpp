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
         so there are n buttons in a row 
         each button has a weight 

        //  create and moves clones ? right 

        you can do unlimited no of operations 
        create a clone in front of a specific button 
        or
        move an existing clone one position to the left or right 
        
        
        u have to press all the buttons in such an order that the sequence of their weights is non- increasing order 

        minimum no of clones in order to press all the buttons 
        in that valid order ? 


      

  -> Your Attacks:
        notice one thing , the max limit is n
        
        we will create a multiset to track the next minimum thing 

        agar 4 5 3 hai , to like maan lo 5 se start kar rha hia 
        5 se 4 gya aur phir 3 

        naah , make it better 

        we have to track the points  , like 
        somehow , its means , like somehow 
        we have to put somepoints onto the
        arrary , and from decreasing order , 
        we have to say , is there any direct connection
        between them 
        and by doing to , we have to remove the numbers or 
        mark the numbers so that for the future one 
        we can get it 


        what about the multiple elements ? 
        set suppose we did rbegin to the set

        we will get x , but if x has occured multiple times ? 

        how to choose that x which will cause no clone addition ? 
        is there any simpler way to do this ? 


        how to mark that guy which benifits the most ? 
        like 

       
        1 1 2
        here at 2 one clone is created 
         
        but how to choose that one which will try to not 
        create any 
        further clone ? 
        should i make marked vector ? 
        and get the nearest true values 
        if the values is +1 or -1 to the index do nothing ? 
        is this the way ? \
        how to decide which one to choose ? 
        what i have 
        : indexs of  some marked elements 
        indexes of current weight 
        how to pick that weight which is adjacent to 
        any marked guy ? in the least tc ? 

        like it can we anything  , anyone can be adjacent to that 
        if i tried to iterate on the marked one it will become n^2 



        i actually went for the implimentation parts isnt it ? 

  -> Hints From Code:

*/

void Chal_Ja_Plz(){
  int n;cin>>n;
  vi a(n);
  invec(a);
  vi b;
  for(int i:a){
    if(b.empty()||b.back()!=i)b.pb(i);
  }
  int ans=0;
  int m=b.size();
  for(int i=0;i<m;i++){
    bool p=true;
    if(i>0&&b[i]<b[i-1])p=false;
    if(i<m-1&&b[i]<b[i+1])p=false;
    if(p)ans++;
  }
  cout<<ans<<endl;
}


// void Chal_Ja_Plz() {
//     int n; 
//     cin >> n;
    
//     // Pair of {value, original_index}
//     vector<pair<int, int>> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i].first;
//         a[i].second = i;
//     }
    
//     // Sort descending by value
//     // If values are equal, order doesn't matter for our logic, 
//     // but sorting descending by index as secondary is a safe default.
//     sort(a.rbegin(), a.rend());
    
//     vector<bool> pressed(n, false);
//     int clones = 0;
    
//     for (int i = 0; i < n; i++) {
//         int idx = a[i].second;
        
//         bool left_pressed = false;
//         bool right_pressed = false;
        
//         if (idx > 0 && pressed[idx - 1]) {
//             left_pressed = true;
//         }
//         if (idx < n - 1 && pressed[idx + 1]) {
//             right_pressed = true;
//         }
        
//         // If neither neighbor is pressed, this is a new isolated island
//         // We MUST create a new clone here.
//         if (!left_pressed && !right_pressed) {
//             clones++;
//         }
        
//         // Mark current as pressed
//         pressed[idx] = true;
//     }
    
//     cout << clones << "\n";
// }
// void Chal_Ja_Plz() {
//     // There is always a simpler solution for the question 
//     int n;cin>>n;
//     vi a(n);
//     invec(a);
//     vi mark(n+1, false);
//     set<int>st;
//     for(int x:a)st.insert(x);
//     map<int,vector<int>>mp;
//     for(int i=0;i<n;i++)mp[a[i]].pb(i);
//     int ans=0;
//     while(!st.empty()){
//       auto it =prev(st.end());
//       int val=*it;
//       st.erase(it);
//       for(int i:mp[val]){
//         if(i+1<n&&mark[i+1]==true){
//           mark[i]=true;
//           continue;
//         }
//         if(i-1>=0&&mark[i-1]==true){
//           mark[i]=true;
//           continue;
//         }
//         mark[i]=true;
//         ans++;

//       }


//     }
//     cout<<ans<<endl;;
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