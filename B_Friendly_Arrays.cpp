#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n), b(m);

        long long X = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            X ^= a[i];
        }

        long long B = 0;
        
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            B |= b[i];
        }

        if(n % 2 == 0) {
            cout << X << " " << X << "\n";
        } else {
            cout << min(X, X ^ B) << " " 
                 << max(X, X ^ B) << "\n";
        }
    }
}