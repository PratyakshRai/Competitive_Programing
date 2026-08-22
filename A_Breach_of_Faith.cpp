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
         we can say it is nothing but 

         -1 +2 -3 +4 .....+2n -2n+1 =0
         all are distinct elements 
         and sum of their even - odd elements is 
         zero 

         somethings to be noticed ::
         all the elements are positive 

         also ai<=10^18 
         but bi<=10^9
         what does it tells ? 
         

         can we take , like 
         sum of odd elements 
         and sum of even elements 
         if odd-even >0 just print differennce, odd,even, odd, even (elements from the array )

         if the difference is negative 
         just do the even then odd 
         
         wait  , it should be pair wise distinct 
         what is after doing the operation
         difference will equal to any of the elements in the array ? 
         
         inshort , 
         we half to put half elements in one container 
         and other half in some other 
         and if their difference doesnot belongs to 
         any of the set , then its good 
         otherwise its bad 

         how should i ensure the difference is unique ? 
         what is the proof , how to make the two sets 
         so that the difference is unique  ? 

         okay we can say 
         we have some elements , after seeing those
         we will get a range  ,like (min, max)
         if we somehow get any other elements outside this range , we can make it 
         otherwise , there will always be doubt that 
         the difference is equal to one of the 
         elements of the array 

         lets take two cases : 
         first we try for min and the max
         
         first we take x=min-1

         so we should have 
         a-b<=x 
         and one element should go to set A and other 
         should go to set B 
         right ? 

         is this the correct way ? 

         dont know 

         what i am sure is that 
         sum (set A)-sum (set B)=d(let)
         so 
         first d>0
         
         second 
         min(array(a))>d or 
         max(array(a))<d
         if this can we achieved throught generalised way 
         then its good ? right ? 

         but its not always possible to achieve this 

         but 
         if we substract largest from the smallest 
         we can get the maximum number 
         is there any possibility that this number 
         is the same number from the array , Yes 
          
         like 2 1 , the difference will be 1 and 1 belongs to the array 
         but then there will be no solution for 
         2 , 1 , rigth ? 


         how can i prove  , if 
        -1 +2 -3 +4 .....+2n -2n+1 =0 
      this is true 
      then substracting hightest - lowest will
      give me the 
      different distinct value 




  -> Your Attacks:
         

  -> Hints From Code:

*/

void Chal_Ja_Plz() {
    int n; cin >> n;

    vector<int> b(2*n);
    for (int i = 0; i < 2*n; i++) cin >> b[i];

    sort(b.begin(), b.end());

    vector<int> a(2*n + 1);

 
    for (int i = 0; i <= n; i++) {
        a[2*i] = b[n + i - 1];
    }


    for (int i = 0; i < n-1; i++) {
        a[2*i + 1] = b[i];
    }

    
    int sum_big = 0, sum_small = 0;

    for (int i = n-1; i < 2*n; i++) sum_big += b[i];
    for (int i = 0; i < n-1; i++) sum_small += b[i];

    a[2*n - 1] = sum_big - sum_small;

   
    for (int x : a) cout << x << " ";
    cout << "\n";
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