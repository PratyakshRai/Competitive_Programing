#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long double> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }

    long double low = 0, high = 1e18; // high = large enough upper bound
    for (int iter = 0; iter < 100; iter++) { // 100 iterations for precision
        long double mid = (low + high) / 2.0;
        long double L = -1e30, R = 1e30;

        for (int i = 0; i < n; i++) {
            long double left = x[i] - v[i] * mid;
            long double right = x[i] + v[i] * mid;
            L = max(L, left);
            R = min(R, right);
        }

        if (L <= R) {
            high = mid; // possible to meet
        } else {
            low = mid; // not possible
        }
    }

    cout << fixed << setprecision(10) << high << "\n";
    return 0;
}
