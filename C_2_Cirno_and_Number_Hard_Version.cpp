/*
    Author: Pratyaksh Rai
    Date: 2026-06-09
    Time: 21:10:35
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
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vi vector<int>
#define vp vector<bool>
#define ff first
#define ss second
#define setbits(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (1ll * (a) * (b / gcd(a, b)))
#define invec(v)   \
  for (int &i : v) \
    cin >> i;
#define srt(v) sort((v).begin(), (v).end())
#define rsrt(v) sort((v).rbegin(), (v).rend())

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
#define printv(v)     \
  for (auto x : v)    \
    cout << x << " "; \
  cout << endl;
#define printmap(m) \
  for (auto x : m)  \
    cout << x.ff << " " << x.ss << endl;

// Custom sort for pairs
bool customsort(const pair<int, int> &a, const pair<int, int> &b)
{
  if (a.ff == b.ff)
    return a.ss < b.ss;
  return a.ff > b.ff;
}

// Anti-Hack Custom Hash for unordered_map
struct custom_hash
{
  static uint64_t splitmix64(uint64_t x)
  {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const
  {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
}; // Use: unordered_map<int, int, custom_hash> safe_map;

// ========================================================================
//                         MATH & NUMBER THEORY
// ========================================================================
// 1. Safe Square Root
int sqr(int n)
{
  int r = sqrtl(n);
  while ((r + 1) * (r + 1) <= n)
    r++;
  while (r * r > n)
    r--;
  return r;
}

// 2. Fast Power modulo
int binpow(int a, int b, int m = MOD)
{
  int res = 1;
  a %= m;
  while (b > 0)
  {
    if (b & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

// 3. Sieve of Eratosthenes (Call sieve() in main if needed)
const int MAX_PRIME = 1e6 + 5;
bool is__prime[MAX_PRIME];
vi _prime;
void sieve()
{
  memset(is__prime, true, sizeof(is__prime));
  is__prime[0] = is__prime[1] = false;
  for (int i = 2; i * i < MAX_PRIME; i++)
    if (is__prime[i])
      for (int j = i * i; j < MAX_PRIME; j += i)
        is__prime[j] = false;
  for (int i = 2; i < MAX_PRIME; i++)
    if (is__prime[i])
      _prime.pb(i);
}

// 4. Combinatorics (Call precompute_factorials() in main if needed)
const int MAXF = 2e5 + 5;
int fact[MAXF], invfact[MAXF];
int modInverse(int n) { return binpow(n, MOD - 2); }
void precompute_factorials()
{
  fact[0] = 1;
  invfact[0] = 1;
  for (int i = 1; i < MAXF; i++)
    fact[i] = (fact[i - 1] * i) % MOD;
  invfact[MAXF - 1] = modInverse(fact[MAXF - 1]);
  for (int i = MAXF - 2; i >= 1; i--)
    invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
}
int nCr(int n, int r)
{
  if (r < 0 || r > n)
    return 0;
  return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

// ========================================================================
//                            PROBLEM LOGIC
// ========================================================================
/*
  -> Small Observations:
         okay so hame n diya gya hona , jo ki bahut small hai ,
         like its n<=10
         right ?
         a jaruri nhi ki repeating digit ho ,jaisa ki example me diya gya hai 333 222 111 ,typo thing , it can be anythin , ye jaruri nhi
         ki uski digits array se mille

         |a-b| ki minimum value btani hai , right ?
         agar a ki sari digits array se aati ho , to ham wahi utha lenge
         right ?

         otherwize how should i find the minimum value
         first check binary search : it the function monotonous , nope , so no binary search ?

         think like a is on the number line
         now you have to pick
         we have to pick the number b as close to the number a
         right ? but the thing is the digits must be from the array ,
         right ?
         so the fisrt thing is
         agar mujhe exact number mill ja rha hai ,array se tb to koi baat hi nhi , mai wahi le lunga , right? aur answer 0 aa jayega , right,
         but agar exact nhi mill rha hai , to mai

         case 1: us number se just bda khojunga ,
         but how ,
        mai msb se traverse karunga aur har ek position par us element se
        just bda ya barabar khojunga ,

        ab the thing is
        let say we have the array 3, 4
        and the a is 3666
        so fist what gonna happen we will write 3 then for 6 there is no number , so we will go back at the position for 3 and increase the number right , the next highest number , right ,
        if we dont find any , then we will move to case 2
        otherwise , we will choose that number here it is 4
        then afterwards we will fill the whole , with the smallest number right ?

        agar mill gya to theek
         case 2: us number se just chhota khojunga , right  ?
         msb se iteration start kar denge , right ?
         how to find the smallest number right ?
         ham try karenge ,kisi bhi element ke brabar ya usse chhota elment khoje , if we cant find , ham ek step piche jayenge aur piche wale element me ek kam try karenge , agar wo bhi nhi ho paya to
         ek aur pichhe jayenge , agar msb par pahuch gye aur koi number nhi milla to msb ko 0 karke aage se sare number large like maximum of the array bhar denge, but msb se pahale agar ek number hame kam mill gya to waha se sab maximum bhar denge


  -> Your Attacks:


  -> Hints From Code:

*/
//it is the code by gemini 
void Chal_Ja_Plz() {
    string a_str;
    int n;
    cin >> a_str >> n;
    
    vi d(n);
    invec(d);
    srt(d);

    int a_len = a_str.length();
    int min_d = d.front();
    int max_d = d.back();
    int a_val = stoll(a_str);

    bool exact_match = true;
    for (char c : a_str) {
        if (find(all(d), c - '0') == d.end()) {
            exact_match = false;
            break;
        }
    }
    if (exact_match) {
        cout << 0 << endl;
        return;
    }

    int greater_val = INF;
    int smaller_val = -INF;

    for (int i = 0; i < a_len; i++) {
        bool valid_prefix = true;
        for (int j = 0; j < i; j++) {
            if (find(all(d), a_str[j] - '0') == d.end()) {
                valid_prefix = false;
                break;
            }
        }
        if (!valid_prefix) continue;

        int current_digit = a_str[i] - '0';
        int next_greater = -1;
        for (int x : d) {
            if (x > current_digit) {
                next_greater = x;
                break;
            }
        }

        if (next_greater != -1) {
            string cand = a_str.substr(0, i);
            cand += to_string(next_greater);
            while (cand.length() < a_len) cand += to_string(min_d);
            greater_val = min(greater_val, stoll(cand));
        }
    }

    int first_non_zero = -1;
    for (int x : d) {
        if (x > 0) {
            first_non_zero = x;
            break;
        }
    }
    if (first_non_zero != -1) {
        string cand = to_string(first_non_zero);
        while (cand.length() < a_len + 1) cand += to_string(min_d);
        greater_val = min(greater_val, stoll(cand));
    }

    for (int i = 0; i < a_len; i++) {
        bool valid_prefix = true;
        for (int j = 0; j < i; j++) {
            if (find(all(d), a_str[j] - '0') == d.end()) {
                valid_prefix = false;
                break;
            }
        }
        if (!valid_prefix) continue;

        int current_digit = a_str[i] - '0';
        int next_smaller = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (d[j] < current_digit) {
                if (i == 0 && d[j] == 0 && a_len > 1) continue;
                next_smaller = d[j];
                break;
            }
        }

        if (next_smaller != -1) {
            string cand = a_str.substr(0, i);
            cand += to_string(next_smaller);
            while (cand.length() < a_len) cand += to_string(max_d);
            smaller_val = max(smaller_val, stoll(cand));
        }
    }

    if (a_len > 1) {
        string cand = "";
        while (cand.length() < a_len - 1) cand += to_string(max_d);
        if (cand != "") smaller_val = max(smaller_val, stoll(cand));
    } else if (d[0] == 0) {
        smaller_val = max(smaller_val, 0LL);
    }

    int ans = INF;
    if (greater_val != INF) ans = min(ans, greater_val - a_val);
    if (smaller_val != -INF) ans = min(ans, a_val - smaller_val);

    cout << ans << endl;
}
// ========================================================================
//                             MAIN FUNCTION
// ========================================================================
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // Uncomment below lines if problem requires precomputation
  // sieve();
  // precompute_factorials();

  int t;
  cin >> t;
  while (t--)
    Chal_Ja_Plz();

  return 0;
}
/*
Three golden rules:
1. Every problem has a solution
2. Every problem has a simpler solution
3. Understand what the problem is pointing to
*/