#include <bits/stdc++.h>
using namespace std;

// ------------------- Typedefs -------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define int long long
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
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
     int sum =0,i=0;
     for( i=0;i<n-2;i++){
      sum+=arr[i];    
    }
    cout<<arr[n-1]-arr[n-2]+sum<<"\n";


    

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
