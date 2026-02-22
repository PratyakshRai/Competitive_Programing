#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

     
        int ones = count(s.begin(), s.end(), '1');
        int zero_blocks = 0;

        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                ++zero_blocks;
                while (i < n && s[i] == '0') ++i;
            } else ++i;
        }

        cout << (ones > zero_blocks ? "Yes\n" : "No\n");
    }

    return 0;
}
