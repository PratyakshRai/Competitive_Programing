#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> bad;
        int current_min = INT_MAX;
        for (int i = 1; i <= n; i++) {
            current_min = min(current_min, a[i]);
            if (a[i] != current_min) {
                bad.push_back(i);
            }
        }

        cout << bad.size() << "\n";
        for (int i = 0; i < (int)bad.size(); i++) {
            cout << bad[i] << (i+1 == bad.size() ? '\n' : ' ');
        }
        if (bad.empty()) cout << "\n";
    }
    return 0;
}
