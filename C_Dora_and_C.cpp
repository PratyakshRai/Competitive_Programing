#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long a, b;
        cin >> n >> a >> b;

        vector<long long> c(n);
        for (auto &x : c) cin >> x;

        long long mn = *min_element(c.begin(), c.end());
        long long mx = *max_element(c.begin(), c.end());

        long long g = gcd(a, b);

        cout << (mx - mn) % g << '\n';
    }

    return 0;
}
