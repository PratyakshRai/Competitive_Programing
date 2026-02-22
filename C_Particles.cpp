#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> c(n);
    long long max_val = -2e18; 
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        max_val = max(max_val, c[i]);
    }

   
    if (max_val <= 0) {
        cout << max_val << endl;
        return;
    }

    long long sum_odd = 0;
    long long sum_even = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] > 0) {
            if ((i + 1) % 2 != 0) {
                sum_odd += c[i];
            } else {
                sum_even += c[i];
            }
        }
    }

    cout << max(sum_odd, sum_even) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}