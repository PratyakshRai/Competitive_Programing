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
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0 , sum=0;
    priority_queue<int>pq;
    for(int i=m;i>=2;i--){
      sum+=a[i];
      if(a[i]>0)pq.push(a[i]);
      while(sum>0){
        int x=pq.top();
        pq.pop();
        sum-=2*x;
        ans++;
      }
    }
sum=0;
while(!pq.empty())pq.pop();
for(int i =m+1;i<=n;i++){
  sum+=a[i];
  if(a[i]<0)pq.push(-a[i]);
  while(sum<0){
    int x=pq.top();
    pq.pop();
    sum+=2*x;
    ans++;
  }
}
cout<<ans<<"\n";
    

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
