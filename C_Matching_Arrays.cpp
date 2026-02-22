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
    
int n, x;
cin>>n>>x;
vector<pair<int,int>>p(n);
for(int i =0;i<n;i++){
  cin>>p[i].first;
  p[i].second=i;
}
vector<int>b(n);
for(int i=0;i<n;i++)cin>>b[i];
sort(all(p));
sort(all(b));
reverse(b.begin (),b.end());
reverse(b.begin(),b.begin()+n-x);

reverse(b.begin()+n-x,b.begin()+n);
int cnt=0;
for(int i=0;i<n;i++){
  cnt+=(p[i].first>b[i]);
}

vector<int>ans(n);
if(cnt!=x){
  cout<<"NO\n";

}
else {
  cout<<"YES\n";
  for(int i=0;i<n;i++){
    ans[p[i].second]=b[i];
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}
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
