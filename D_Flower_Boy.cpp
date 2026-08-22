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
         n flow, with ai beauty
         exactly m should be collected
         walk from left to rigth
         choose wheather to select or not

         suppose he collect m flowers
         the ith flower should have beauti
         atleast bi ;')

         it might be possible that you cant
         make exact m flowers

         so you just pick any integers k
         grow a new flower with beauti k
         and place it anywhere in the garden

         can do this atmost onces
         k can be 0 if he can choose without
         any operations
         otherwise output the minimum k


  -> Your Attacks:
         okay so we have to collect m flowers ,
         let suppose we inserted x anywhere
         not anywhere , we will insert it to the adjacent of previsously picked flower ,
         so that after that we will need the x

         since m is tight bound we have to care for b

         what is the problem now ?
         after getting the leftmost element
         for bi
         we have to delect the left of that element
         also
         kya ye sahi hoga , ki jab jarurat hai tabhi use kar rhe hai ?
         like

         okay it is quite often that
         let 4 hai bi
         to 4 se<= left most element khojenge let x
         phir uske left ka delect kardenge
         phir dekhenge ki x ke right me bache hue
         elements kya bi ke 4 ke right me bache hue no of elements ko satisfy kr rhe hai ? agar diff >1 , then its not possible
         if diff <=1 then it might be , in future , right ?

         i know there is just a greedy  ,
         like hame har ek position ke liye check
         karna padega ki k=bi lene se baat bn rhi hai ki nhi , kyuki hame k minimum
         chahiye aur minimum bi me se hi koi ek hoga (0 hoga agar izzat se banjaye )
         but how to do this ?
         kya ye question straight forward hai
         like jha diff==1 hai wahi add krdo  ?

         because i'am adding , it will change the future , so i have to iterate it again , which is not good

         mai ye kahna chahta hu , ki
         kyu ki hame min chahiye , to
         ye jaruri nhi ki left wale saare elements
         sufficient hai ya nhi
         hame add karna ya na karna wali possibility dekhni hai
         but phir baat wahi aa jati hai ki addd karne se future change ho jayega ?

         phir kaise karenge ?
         i think observation


         considerring jaha jaurat pade wahi add kro wali
         thing , no greedy

         then how to do this ?
         what is the problem i have , to remove all the
         elments of left portion which searching for the
         bith element it can be done , think so ;)



  -> Hints From Code:

*/

void Chal_Ja_Plz()
{
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  vector<int> pref(m, INF);
  vector<int> suff(m, -1);

  int ptr_a = 0;
  for (int i = 0; i < m; i++)
  { 
    while (ptr_a < n && a[ptr_a] < b[i])
    {
      ptr_a++;
    }
    if (ptr_a < n)
    {
      pref[i] = ptr_a;
      ptr_a++;
    }
    else
    {
      break;
    }
  }

  if (pref[m - 1] != INF)
  {
    cout << 0 << "\n";
    return;
  }

  ptr_a = n - 1;
  for (int i = m - 1; i >= 0; i--)
  {
    while (ptr_a >= 0 && a[ptr_a] < b[i])
    {
      ptr_a--;
    }
    if (ptr_a >= 0)
    {
      suff[i] = ptr_a;
      ptr_a--;
    }
    else
    {
      break;
    }
  }

  int min_k = INF;

  for (int i = 0; i < m; i++)
  {

    bool left_ok = (i == 0) || (pref[i - 1] != INF);
    bool right_ok = (i == m - 1) || (suff[i + 1] != -1);

    if (left_ok && right_ok)
    {
      int left_idx = (i == 0) ? -1 : pref[i - 1];
      int right_idx = (i == m - 1) ? n : suff[i + 1];

      if (left_idx < right_idx)
      {
        min_k = min(min_k, b[i]);
      }
    }
  }

  if (min_k == INF)
    cout << -1 << "\n";
  else
    cout << min_k << "\n";
}

// void Chal_Ja_Plz() {
//     // There is always a simpler solution for the question
//     int n,m;cin>>n>>m;
//     vi a(n),b(m);
//     invec(a);
//     invec(b);
//     int ans=0;
//     map<int,vector<int>>mp;
//     for(int i=0;i<n;i++)mp[a[i]].pb(i);
//     int curr=0;
//     for(int i=0;i<m;i++){
//       auto  it =mp.lower_bound(b[i]);
//     int val=it->ff;
//     auto &vec=mp[val];
//     auto f=lower_bound(vec.begin(),vec.end(),curr);
//     if(f!=vec.end()){
//       if(n-*f>=(m-i)){
//       curr=*f;}
//       else if (m-i-n+(*f)==1){
//         ans=b[i];
//         curr++;
//       }
//       else {
//         cout<<"-1\n";return;
//       }
//     }else{
//       if(m-i==1){
//         ans=b[i];
//       }else {
//         cout<<"-1\n";return;
//       }
//     }

//     }
//     cout<<ans<<endl;

// }

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