#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (0 <= x && x <= n) freq[x]++;
        }

        int missing = 0;
        for (int x = 0; x < k; ++x) if (freq[x] == 0) missing++;

        int cnt_k = freq[k]; 
        cout << max(missing, cnt_k) << '\n';
    }
    return 0;
}
