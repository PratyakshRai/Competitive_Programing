#include <bits/stdc++.h>
using namespace std;
#define int long long 
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
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>usb,ps;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      int x;
      string type;
      cin>>x>>type;
      if(type=="USB")usb.push_back(x);
      else ps.push_back(x);
    }
    sort(all(usb));
    sort(all(ps));
    int total=0,cnt=0;
    for(int i=0;i<a&&i<usb.size();i++){
      total+=usb[i];
      cnt++;
      usb[i]=-1;
    }

   for(int i=0;i<b&&i<ps.size();i++){
      total+=ps[i];
      cnt++;
      ps[i]=-1;
    }
    vector<int>rest;
    for(auto x:usb)if(x!=-1)rest.push_back(x);
        for(auto x:ps)if(x!=-1)rest.push_back(x);
        sort(all(rest));
        for(int i=0;i<c&&i<rest.size();i++){
          cnt++;
          total +=rest[i];
        }
    cout<<cnt<<" "<<total ;
    return ;

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
    // cin >> t;  // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
