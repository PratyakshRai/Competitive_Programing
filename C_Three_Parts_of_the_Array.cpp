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
     int n;
     cin>>n;
     int ans=0;
     vector<int>a(n);
     for(int i =0;i<n;i++)cin>>a[i];
     int l=a[0], r=a[n-1];
     int i=0, j=n-1;
     while(i<j){
      if(l==r){
        ans=max(ans, l);
      }
      if(l<r){
      i++;
        l+=a[i];
      }
      else {  j--;
        r+=a[j];
        
      }
     }

cout<<ans;
    

}

// ------------------- Main Function --------------
signed  main() {
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
