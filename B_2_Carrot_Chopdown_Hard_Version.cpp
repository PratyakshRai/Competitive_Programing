#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

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

const int INF = 1e18;
const int MOD = 1e9 + 7;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dx8[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy8[8] = {0, 0, 1, -1, 1, -1, 1, -1};

#define printv(v)       for(auto x : v) cout << x << " "; cout << endl;
#define printmap(m)     for(auto x : m) cout << x.ff << " " << x.ss << endl;

bool customsort(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.ff == b.ff) return a.ss < b.ss;
    return a.ff > b.ff;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int sqr(int n) { int r=sqrtl(n); while((r+1)*(r+1)<=n)r++; while(r*r>n)r--; return r; }
int binpow(int a, int b, int m = MOD) {
    int res = 1; a %= m;
    while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; }
    return res; 
}

const int MAX_PRIME = 1e6 + 5;
bool is__prime[MAX_PRIME];
vi _prime;

void sieve() {
    memset(is__prime, true, sizeof(is__prime)); is__prime[0] = is__prime[1] = false;
    for(int i=2; i*i<MAX_PRIME; i++) if(is__prime[i]) for(int j=i*i; j<MAX_PRIME; j+=i) is__prime[j] = false;
    for(int i=2; i<MAX_PRIME; i++) if(is__prime[i]) _prime.pb(i);
}

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

void Chal_Ja_Plz() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    invec(a);
    
    vi pref(m + 2, 0);
    for (int x : a) {
        if (x <= m) pref[x]++;
    }
    for (int i = 1; i <= m + 1; i++) {
        pref[i] += pref[i - 1];
    }
    
    vi global_max(m + 2, 0);
    vi pref_pieces(m + 2, 0);
    
    for (int i = 1; i <= m; i++) {
        int max_c = m / i;
        
        for (int c = 1; c <= max_c; c++) {
            int right_idx = min(c * i + i - 1, m);
            int count_in_range = pref[right_idx] - pref[c * i - 1];
            pref_pieces[c] = pref_pieces[c - 1] + count_in_range * c;
        }
        
        for (int k = 1; ; k++) {
            int C = (k >= 30) ? INF : ((1LL << k) - 1);
            
            if (C >= max_c) {
                if (k <= m) {
                    global_max[k] = max(global_max[k], pref_pieces[max_c]);
                }
                break;
            } else {
                int base_sum = pref_pieces[C];
                int rem_elements = pref[m] - pref[(C + 1) * i - 1];
                int exact_bonus = pref[(C + 1) * i] - pref[(C + 1) * i - 1];
                
                int ans = base_sum + rem_elements * C + exact_bonus;
                if (k <= m) {
                    global_max[k] = max(global_max[k], ans);
                }
            }
        }
    }
    
    for (int k = 1; k <= m; k++) {
        global_max[k] = max(global_max[k], global_max[k - 1]);
        cout << global_max[k] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    
    return 0;
}