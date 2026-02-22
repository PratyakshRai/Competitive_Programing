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


int count(int target, vector<int>&a,int n)
{
  int cnt =0;
int i =0;
int j=n-1;
while(i<j){
  if(a[i]+a[j]<=target){
    cnt+=j-i;
    i++;
  }
  else j--;
}
return cnt;
}
// ------------------- Solve Function -------------
void solve() {
    int n,l, r;
    cin>>n>>l>>r;
    vector<int>a(n);
    for(int i =0;i<n;i++)cin>>a[i];
    int j=n-1;
    int i=0;
    sort(all(a));
  int cnt1=count(l-1,a,n);
  int cnt=count(r, a,n);
  cout<<cnt-cnt1<<endl;
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
