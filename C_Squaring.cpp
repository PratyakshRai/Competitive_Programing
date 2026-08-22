#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long total_ops = 0;
    long long current_c = 0;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > 1 && a[i] == 1) {
            cout << -1 << "\n";
            return;
        }
        if(a[i-1]==1)continue;
      

        long long x = a[i - 1];
        long long y = a[i];

        if (x > y) {
            long long v = 0;
            while (x > y) {
                y = y * y;
                v++;
            }
            current_c = current_c + v;
        } else {
            long long v = 0;
            while (x <= y) {
                x = x * x;
                v++;
            }
            current_c = max(0LL, current_c - v + 1);
        }
        total_ops += current_c;
    }
    cout << total_ops << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}