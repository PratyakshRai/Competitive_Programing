#include <bits/stdc++.h>
using namespace std;

// ------------------- Typedefs -------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// ------------------- Macros ---------------------
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

// ------------------- Constants ------------------
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// ------------------- Debugger -------------------
#ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ", _print(x)
#else
    #define debug(x...)
#endif

void _print(int x) { cerr << x << '\n'; }
void _print(long x) { cerr << x << '\n'; }
void _print(ll x) { cerr << x << '\n'; }
void _print(unsigned x) { cerr << x << '\n'; }
void _print(unsigned long x) { cerr << x << '\n'; }
void _print(unsigned long long x) { cerr << x << '\n'; }
void _print(float x) { cerr << x << '\n'; }
void _print(double x) { cerr << x << '\n'; }
void _print(long double x) { cerr << x << '\n'; }
void _print(char x) { cerr << '\'' << x << '\'' << '\n'; }
void _print(const char *x) { cerr << '\"' << x << '\"' << '\n'; }
void _print(const string &x) { cerr << '\"' << x << '\"' << '\n'; }
void _print(bool x) { cerr << (x ? "true" : "false") << '\n'; }

template <typename T, typename V> void _print(const pair<T, V> &x) {
    cerr << '{'; _print(x.first); cerr << ','; _print(x.second); cerr << '}';
}
template <typename T> void _print(const T &x) {
    cerr << '{'; bool first = true;
    for (const auto &i : x) {
        if (!first) cerr << ", ";
        _print(i); first = false;
    }
    cerr << "}\n";
}
void solve() {
     int n, x;
        string s;
        cin >> n >> x >> s;
        if(x==1 || x==n) {
            cout << "1\n";
          return;
        }
        x--;
        int inf = 1e9;
        int lf=-inf, rg=inf;
        for(int i=x-1; i>=0; i--)
            if(s[i]=='#') {
                lf=i;
                break;
            }
        for(int i=x+1; i<n; i++)
            if(s[i]=='#') {
                rg=i;
                break;
            }
        if(lf==-inf && rg==inf) {
            cout << "1\n";
            return;
         }  
            // cout<<max(min(lf + 2, n - rg + 1), min(x + 1, n - x))<<'\n';
        cout << max(min(x+1, n-rg+1), min(lf+2, n-x)) << '\n';
}


// ------------------- Solve Function -------------
// void solve() {
//     int n, h;
//     cin >> n >> h;
//     h--;  // Convert to 0-based index
//     string wall;
//     cin >> wall;

//     if (h == 0 || h == n - 1) {
//         cout << 1 << "\n";
//         return;
//     }

//     int left = -INF, right =INF;

//     // find nearest wall on the left
//     for (int i = h - 1; i >= 0; i--) {
//         if (wall[i] == '#') {
//             left = i;
//             break;
//         }
//     }

//     // find nearest wall on the right
//     for (int i = h + 1; i < n; i++) {
//         if (wall[i] == '#') {
//             right = i;
//             break;
//         }
//     }
// if(left==-INF&&right==INF){
//     cout<<"1\n";
//     return;
// }
//     int ans = max(min(left + 2, n - right + 1), min(h + 1, n - h));
//     cout << ans << "\n";
// }

// ------------------- Main Function --------------
int main() {
    ios_base::sync_with_stdio(false);

    // freopen("bcount.in", "r", stdin);  for ucaso problems , put the name of the .in which is given 
   // freopen("bcount.out", "w", stdout);
  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);     // for local input
    freopen("output.txt", "w", stdout);   // for local output
    freopen("error.txt", "w", stderr);    // for debug output
#endif
    cin.tie(NULL);

    int t = 1;
    cin >> t;  // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
