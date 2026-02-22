#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool>removed(n+1,false);
    ll sum = 0; // use long long

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
          if(s[j-1]=='1')break;
            if (s[j - 1] == '0'){
              if(!removed[j-1]){
                sum+=i;
                removed[j-1]=true;
              }
            }
        }
    }

    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
