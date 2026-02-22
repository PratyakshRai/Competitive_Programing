#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    // Case 1: already all c
    bool all_c = true;
    for (char ch : s) {
        if (ch != c) {
            all_c = false;
            break;
        }
    }
    if (all_c) {
        cout << 0 << "\n";
        return;
    }

    // Case 2: check if 1 operation possible
    for (int x = 1; x <= n; x++) {
        bool ok = true;
        for (int j = x; j <= n; j += x) {
            if (s[j - 1] != c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << 1 << "\n" << x << "\n";
            return;
        }
    }
    // Case 3: otherwise 2 operations (n and n-1 works)
    cout << 2 << "\n" << n << " " << n - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
