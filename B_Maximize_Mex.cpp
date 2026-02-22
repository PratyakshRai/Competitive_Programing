#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &v : a) cin >> v;

    // Use unordered_map to store only needed values
    unordered_map<int,int> freq;


    // Only freq of values <= n matter initially
    for (int v : a) {
        if (v <= n) freq[v]++;
    }

    for (int k = 0; k <= n; k++) {
        if (freq[k] == 0) {
            cout << k << "\n";   // first missing -> MEX
            return;
        }

        // If multiple copies, shift duplicates to k + x
        if (freq[k] > 1) {
            int extra = freq[k] - 1;
            freq[k] = 1;
            freq[k + x] += extra;   // SAFE because only a few entries appear
        }
    }

    // If all 0..n are present → MEX = n+1
    cout << n + 1 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
