#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    int k = r - l + 1;

    // Case 1: range [1..r]
    vector<int> c1(a.begin(), a.begin() + r + 1);
    sort(c1.begin(), c1.end());
    int s1 = 0;
    for(int i = 0; i < k; i++) s1 += c1[i];

    // Case 2: range [l..n]
    vector<int> c2(a.begin() + l, a.end());
    sort(c2.begin(), c2.end());
    int s2 = 0;
    for(int i = 0; i < k; i++) s2 += c2[i];

    cout << min(s1, s2) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}
