#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;  // k = 0 in this version
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> cur_a = a;
        int rounds = 0;
        bool done = false;

        while (!done) {
            rounds++;
            // Step 1: pairwise reduction
            for (int i = 0; i < n; i++) {
                int t = min(cur_a[i], b[i]);
                cur_a[i] -= t;
                b[i] -= t; // optional, not necessary if b is reused
            }

            // Step 2: rotate left
            vector<int> tmp(n);
            for (int i = 0; i < n; i++) {
                tmp[i] = cur_a[(i - 1 + n) % n];
            }
            cur_a = tmp;

            // Step 3: check if all zero
            done = true;
            for (int i = 0; i < n; i++) {
                if (cur_a[i] > 0) {
                    done = false;
                    break;
                }
            }
        }

        cout << rounds << "\n";
    }

    return 0;
}
