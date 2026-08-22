#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

     
        vector<long long> digits;
        long long temp = n;

        while (temp > 0) {
            digits.push_back(temp % 3);
            temp /= 3;
        }

        long long sum_digits = 0;
        for (auto d : digits) {
            sum_digits += d;
        }

        if (sum_digits > k) {
            cout << -1 << "\n";
            continue;
        }

      
        vector<long long> pow3(25, 1);
        for (int i = 1; i < 25; i++) {
            pow3[i] = pow3[i - 1] * 3;
        }

        long long ans = 0;

        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] == 0) continue;

            if (i == 0) {
               
                ans += digits[i] * 3;
            } else {
               
                ans += digits[i] * ( (i + 9) * pow3[i - 1] );
            }
        }

        cout << ans << "\n";
    }

    return 0;
}