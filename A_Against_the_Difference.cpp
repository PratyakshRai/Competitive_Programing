#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> dp(n+1, 0);
        vector<vector<int>> pos(n+1);  // store positions of each value

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1]; // case 1: skip a[i]
            int val = a[i];
            pos[val].push_back(i);

            // case 2: use a[i] in a block
            if ((int)pos[val].size() >= val) {
                int x = pos[val][pos[val].size() - val]; // starting index of this block
                dp[i] = max(dp[i], dp[x-1] + val);
            }
        }

        cout << dp[n] << "\n";
    }
    return 0;
}
