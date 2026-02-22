#include <bits/stdc++.h>
using namespace std;
#define int long long 
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



// ------------------- Solve Function -------------
void solve() {
    long long a, b;
    cin >> a >> b;

    int checka = a & 1;
    int checkb = b & 1;

    if (!checka && !checkb) { 
        // a and b both even → best k = b/2
        cout << 2 + (a * b) / 2 << '\n';
    }
    else if (!checka && checkb) { 
        // a even, b odd → impossible
        cout << -1 << '\n';
    }
    else if (checka && (b % 2 == 0) && (b % 4 != 0)) { 
        // a odd, b divisible by 2 but not 4 → impossible
        cout << -1 << '\n';
    }
    else if (checka && (b % 4 == 0)) { 
        // a odd, b divisible by 4 → best k = b/2
        cout << 2 + (a * b) / 2 << '\n';
    }
    else { 
        // a and b both odd → best k = b
        cout << a * b + 1 << '\n';
    }
}

// ------------------- Main Function --------------
signed main() {
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
