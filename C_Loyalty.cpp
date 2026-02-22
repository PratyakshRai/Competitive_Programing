#include <bits/stdc++.h>
using namespace std;

// ------------------- Typedefs -------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// ------------------- Macros ---------------------
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define int long long
// ------------------- Constants ------------------
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// ------------------- Debugger -------------------
#ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ", _print(x)
#else
    #define debug(x...)
#endif

// ------------------- Solve Function -------------
void solve() {
    int n,x;cin>>n>>x;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(all(v));
    int p1=0, p2=n-1;
    int s=0 , ans=0;
    vector<int>arr;
    while(p1<=p2){
        int need=x-(s%x);
        if(v[p2]>=need){
            s+=v[p2];
            ans+=v[p2];
            arr.push_back(v[p2]);
            p2--;
        }
        else {
            s+=v[p1];
            arr.push_back(v[p1]);
            p1++;
            continue;
        }
    }
    cout<<ans<<endl;
    for(auto i : arr)cout<<i<<" ";
    cout<<endl;
    return;

}

// ------------------- Main Function --------------
signed main() {
    ios_base::sync_with_stdio(false);

    // freopen("bcount.in", "r", stdin);  for ucaso problems , put the name of the .in which is given 
   // freopen("bcount.out", "w", stdout);
  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);     // for local input
    freopen("output.txt", "w", stdout);   // for local output
    freopen("error.txt", "w", stderr);    // for debug output
#endif
    cin.tie(NULL);

    int t = 1;
     cin >> t;  // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
