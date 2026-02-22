#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

   
 
    int curr =0;
    int ans=k;
    for(int i=0;i<n;i++){
        a[i]-=curr;
        k-=min(k,(n-i)*a[i]);
        if(k==0)break;
        else ans++;
        curr+=a[i];
        
    }
    cout<<ans<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
