#include <bits/stdc++.h>
using namespace std;

long long minSwaps(const string &s, char ch) {
    vector<int> pos;
    int n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == ch) pos.push_back(i);

    int k = pos.size();
    if (k <= 1) return 0;

    vector<long long> norm(k);
    for (int i = 0; i < k; i++)
        norm[i] = pos[i] - i;

    sort(norm.begin(), norm.end());
    long long median = norm[k / 2];

    long long res = 0;
    for (int i = 0; i < k; i++)
        res += llabs(norm[i] - median);

    return res;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << min(minSwaps(s, 'a'), minSwaps(s, 'b')) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
