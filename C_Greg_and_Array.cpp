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
   int n,m,k;cin>>n>>m>>k;
   vector<int>arr(n);
   for(int &a: arr)cin>>a;
   vector<int>l(m),r(m),d(m);
   for(int i =0;i<m;i++){
    cin>>l[i]>>r[i]>>d[i];
    l[i]--;
    r[i]--;
   }
   vector<int>diff(m+1,0);
   for(int i =0;i<k;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    diff[x]+=1;
    if(y+1<m)diff[y+1]-=1;
   }
   vector<int>cnt(m,0);
   cnt[0]=diff[0];
   for(int i=1;i<m;i++){
    cnt[i]=cnt[i-1]+diff[i];
   }
   vector<int>fn(n+1,0);
   for(int i=0;i<m;i++){
    fn[l[i]]+=d[i]*cnt[i];
    if(r[i]+1<n)fn[r[i]+1]-=d[i]*cnt[i];
   }
   for(int i =0;i<n;i++){
    if(i>0)fn[i]+=fn[i-1];
    arr[i]+=fn[i];
   }
   for(int i =0;i<n;i++)cout<<arr[i]<<" ";
   

    

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
