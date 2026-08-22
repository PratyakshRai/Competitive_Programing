/*
    Author: Pratyaksh Rai
    Date: 2026-04-05
    Time: 14:04:31
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
         so there is  a number line 
         and some person , ai , 
         ai have to go to bi 
         also all ai < bi like har ek person ko aage hi jana hai 
         ayesa bhi ho sakta hai ki ek bande ka destination dusare ke 
         starting point se pahale  ho 
         all people start moving at the speed of 1 m/s , 
         until they reach their destination 
         when two people meet at the same point they gonna
         greeet each other 

         how many greetings ? 
         ek baat to pakki hai 
         sabki relavetive speed 0 hai 
         like sab 1 se move kar rhe hai 
         to jab tk koi rukega nhi tab tk greeting possible hi nhi hai 

         dhyan se dekho , isme do baate hai 
         ek to jo line me aage hai usko kam mauke millenge , aur jo peeche hai usko jade 
         dusara , ending point kya hai ? 


         so , i think for a particular point (x let )
         let destination is y , then kaise cases banenge greeting ke ? 
         x aur y ke beech me kitno ka final point hai , aur unme se 
         kitne (starting point ) x se bade hai , like i mean x aur y 
         ke beech me kitne start hue aur khatam ho gye  

         case two ? 
         x se peeche kitno ka destination y se bda hai ? 
         count that also 

         yaha par do baar count ho rha hai , to ham in dono case me se koi ek case le sakte hai  ? right ? 

         to ham wo waala case choose karenge jisme hame ek pair ke liye , ye dekhna hai ki use andar kitna aise pair hai 
         jo start hoke end ho ja rhe hai , 
         aur ham chhote se bade(starting point ) ki taraf jayeinge  

         now the thing is how to implement this shit ? 


         main pair bna lunga , (start , end )
         aur sort bhi kar lunga 
         aur binary search lga ke ye bhi pta karlunga ki 
         kaunsa start point mere x (let )start ke bda hai 
         but how should i find out how many of the end from those starts 
         will end before my xth end point ? 

         i can think of second case also :
         like mere x starting point se pahale kitne ayese hai jo 
         mere x ke ending point ke baad jaye end hote hai  ? 

         dekho binary search karke ye to pta kar lunga ki 
         x se chhote kitne starting point hai 
         aur x ke ending point se bade kitne ending point hai 

         par dikkat matching pair ki hai 
         ki un starting aur ending points me matching pair kitna hai ? 
         how to find that in less time complexity ?           

  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
    int n;cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
      cin>>a[i].ff>>a[i].ss;
    }
    srt(a);
    int ans=0;
    ordered_set bag;
    for(int i=n-1;i>=0;i--){
      int e=a[i].ss;
      ans+=bag.order_of_key(e);
      bag.insert(e);
    }
    cout<<ans<<endl;
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