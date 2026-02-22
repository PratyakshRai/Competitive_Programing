#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
    } else {
        swap(arr[0], arr[1]);
        for (int i = 2; i < n - 1; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
