#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    int last = 0;
    for (int i = 1; i <= n; i++) {
       if(a[i]>last){
        b[i]=i-1;
        last=i;
       }
       else {
        b[i]=1e6;
       }
    }

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}
