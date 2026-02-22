#include <bits/stdc++.h>
using namespace std;

// ------------------- Typedefs -------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// ------------------- Constants ------------------
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

vector<ll> facts;

void precompute_factorials() {
    ll f = 1;
    for (int i = 1; i <= 14; ++i) {
        f *= i;
        facts.push_back(f);
    }
}

// ------------------- Solve Function -------------
void solve() {
    ll x;
    cin >> x;

    // If x is a power of 2
    if ((x & (x - 1)) == 0) {
        cout << 1 << "\n";
        return;
    }

    int n = facts.size();
    int mincnt = INT_MAX;

    for (int mask = 0; mask < (1 << n); ++mask) {
        ll sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += facts[i];
                ++cnt;
            }
        }

        if (sum > x) continue;

        ll rem = x - sum;
        mincnt = min(mincnt, __builtin_popcountll(rem) + cnt);
    }

    cout << (mincnt != INT_MAX ? mincnt : -1) << "\n";
}

// ------------------- Main Function --------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);     // for local input
    freopen("output.txt", "w", stdout);   // for local output
    freopen("error.txt", "w", stderr);    // for debug output
#endif

    precompute_factorials(); // FIXED: Only compute once!

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
