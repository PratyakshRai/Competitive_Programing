#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double c;
    cin >> c;

    double low = 0.0, high = c; // search range
    while (high - low > 1e-7) {
        double mid = (low + high) / 2.0;
        double f = mid * mid + sqrt(mid);

        if (f < c)
            low = mid;  // need bigger x
        else
            high = mid; // too big
    }

    cout << fixed << setprecision(10) << low << "\n";
    return 0;
}
