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
ll n;cin>>n;
char g[n][n];
for(ll i=0;i<n;i++){
  
    string s;
    cin>>s;
    for(ll j =0;j<n;j++){
      g[i][j]=s[j];
    }
  
}
multiset<ll>sum,diff,x,y;
for(ll i=0;i<n;i++){
  for(ll j=0;j<n;j++){
    if(g[i][j]=='#'){
      sum.insert(i+j);
      diff.insert(i-j);
      x.insert(i);
      y.insert(j);
    }
  }
}
if(x.size()<2){
  cout<<"YES\n";
  return;

}

bool check =false;
		check |= ( (*(--x.end()) - *x.begin() <= 1) && (*(--y.end()) - *y.begin() <= 1) );
		check |= (*(--sum.end()) - *sum.begin() <= 1);
		check |= (*(--diff.end()) - *diff.begin() <= 1);
 if(!check)cout<<"NO\n";
 else cout<<"YES\n";
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
