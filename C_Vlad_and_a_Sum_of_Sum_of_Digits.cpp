#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sumDigits(ll x) {
    ll s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<ll> queries(t);
    ll maxn = 0;
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
        maxn = max(maxn, queries[i]);
    }

    vector<ll> ans(maxn + 1, 0);
    for (ll i = 1; i <= maxn; i++) {
        ans[i] = ans[i - 1] + sumDigits(i);
    }

    for (ll n : queries) {
        cout << ans[n] << "\n";
    }
}
