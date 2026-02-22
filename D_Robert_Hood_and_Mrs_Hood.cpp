#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;
        int m = n - d + 1; // number of valid start positions
        vector<int> diff(max(1, m + 2), 0); // size at least m+2, but if m==0 (shouldn't happen since d<=n) handle safely

        for (int i = 0; i < k; ++i) {
            int l, r; cin >> l >> r;
            // s in [ l - d + 1, r ] intersects interval
            int L = l - d + 1;
            int R = r;
            // clamp to [1, m]
            L = max(L, 1);
            R = min(R, m);
            if (L <= R) {
                diff[L] += 1;
                diff[R + 1] -= 1;
            }
        }

        // compute counts
        vector<int> cnt(m + 1, 0); // 1-based index for s = 1..m
        int cur = 0;
        for (int s = 1; s <= m; ++s) {
            cur += diff[s];
            cnt[s] = cur;
        }

        // find earliest maximum and earliest minimum
        int bestMaxS = 1;
        int bestMinS = 1;
        for (int s = 1; s <= m; ++s) {
            if (cnt[s] > cnt[bestMaxS]) bestMaxS = s;
            if (cnt[s] < cnt[bestMinS]) bestMinS = s;
        }

        // print results: brother (max), mother (min)
        cout << bestMaxS << " " << bestMinS << "\n";
    }
    return 0;
}
