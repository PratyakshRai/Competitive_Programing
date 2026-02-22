#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> divisors;

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end());

    if (divisors.size() >= k) {
        cout << divisors[k - 1] << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(); // Only one test case
    return 0;
}
