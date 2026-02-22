#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    pair<int,int> f = {a, b};
    pair<int,int> o = {0, 0}, total = {0, 0};
    set<pair<int,int>> st;
    st.insert(o);

    for (char c : s) {
        if (c == 'N') o.second++;
        else if (c == 'S') o.second--;
        else if (c == 'E') o.first++;
        else if (c == 'W') o.first--;
        st.insert(o);
    }

    total = o;

    // Check if f is directly in path
    if (st.find(f) != st.end()) {
        cout << "YES\n";
        return;
    }

    // Avoid division by zero
    if (total.first == 0 && total.second == 0) {
        cout << "NO\n";
        return;
    }

    int xmul = (total.first != 0) ? (f.first / total.first) : 0;
    int ymul = (total.second != 0) ? (f.second / total.second) : 0;
    int multiplier = min(xmul, ymul);

    f.first -= total.first * multiplier;
    f.second -= total.second * multiplier;

    cout << (st.find(f) != st.end() ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
