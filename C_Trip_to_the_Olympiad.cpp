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
         so there will be many oplympiads 
         a team of three pupils 
         
         wtf is tha question ? 
         how do i even solve this ? 
         each pupil has an independence level expressed as an integer 
         so we are given a range 
         (l , r)

         choose three integer : 
         a , b , c so that the value for a^b+ b^c +c^a is maximized 

         2^30 means 10 to the power 9 

         let you have three bits 
         a , b , c 
         they are single bits
         
         what is the maximum value that can be achieved 
         by 
         a^b + b^c + c^a ? 
         for 
         1 1 1 its 0 
         1 1 0 and all its permutation , its 2
         for 1 0 0 , its 2 again 
         hence for a particular ith bit position we can set 
         atmax two bits in two numbers , and at min 
         one bit in one of the numbers , 

         hame bass ye dhyan dena hai ki a, b , c teeno l aur r ke andar hoye 

         how should i get into the range (l,r) ? 
         how to get the result into the range ? 
         okay , i will take a in one team and b,c in other team 
          
         a will incline towards higest , and b,c will inclined towards 
         lowest 
         let we are at the ith bit 

         if the bit is set only in R , then i will set that bit only in a 
         if the bit is set  in R and  L or only L  , then i will set that bit in both b,c 
         if the bit is set in none of them i will set that bit in both b , and c , but note this should be the position less than the highest set bit position 

        


  -> Your Attacks:
         

  -> Hints From Code:

*/
void Chal_Ja_Plz() {
   int l, r;
    cin >> l >> r;
    int k = 31 - __builtin_clz(l ^ r);
    int a = l | ((1 << k) - 1), b = a + 1, c = (a == l ? r : l);
    cout << a << " " << b << " " << c << "\n";
}
// void Chal_Ja_Plz() {
//     // There is always a simpler solution for the question 
//     int l , r;cin>>l>>r;
//     if (l == r) {
//         cout << l << " " << l << " " << l << endl;
//         return;
//     }
//     int a=0,b=0,c=0;
//     int pos=63-clz(r);
//     int mask=l^r;
//     int k=63-clz(mask);
//     b=(r>>k)<<k;
//     a=b-1;
//     c=a;
//     cout<<a<<" "<<b<<" "<<c<<endl;
//     // for(int i=0;i<pos;i++){
//     //     int t=(1LL<<i);
//     //     bool L=((t&l)!=0)?true:false;
//     //     bool R=((t&r)!=0)? true:false;
//     //     if(L&&(R==false)){
//     //         a|=t;
            
//     //     }else {
//     //         b|=t;
//     //         c|=t;
//     //     }
//     // }
//     // cout<<a<<" "<<b<<" "<<c<<endl;
//     // // cout<<(a^b)+(b^c)+(c^a)<<endl;
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