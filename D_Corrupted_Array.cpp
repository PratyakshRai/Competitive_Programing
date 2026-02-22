#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n + 2);
    for (int i = 0; i < n + 2; i++) cin >> b[i];
   
 sort(b.begin(), b.end());
    long long total = accumulate(b.begin(), b.end(), 0LL);

    // Case 1: assume last element b[n+1] is sum(a)
    for (int i = 0; i < n + 2; i++) {
        if (i == n + 1) continue; // skip sum(a) itself
        if (total - b[n+1] - b[i] == b[n+1]) {
            for (int j = 0; j < n + 2; j++) {
                if (j == i || j == n+1) continue;
                cout << b[j] << " ";
            }
            cout << "\n";
            return;
        }
    }

    // Case 2: assume b[n] is sum(a), b[n+1] is extra
    if (total - b[n] - b[n+1] == b[n]) {
        for (int j = 0; j < n + 2; j++) {
            if (j == n || j == n+1) continue;
            cout << b[j] << " ";
        }
        cout << "\n";
        return;
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
