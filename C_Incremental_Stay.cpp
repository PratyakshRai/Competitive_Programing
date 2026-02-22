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


int calculate(int i, int j, vector<int>&arr){
  int sum =0;

  while(i<j){
    sum+=arr[j]-arr[i];
    i++;
    j--;
  }
  return sum;
}
// ------------------- Solve Function -------------`====
void solve() {
 ll n; cin>>n;
 vector<int>v;
 for(ll i =0;i<2*n;i++){
  ll x ;cin>>x;v.push_back(x);

 }
 vector<ll>ans(n+3,0);
 for(ll i =0 ; i<2*n;i+=2)ans[1]-=v[i];
 for(ll i = 1;i<2*n;i+=2){
  ans[1]+=v[i];ans[2]-=v[i];
 }
 for(int i =2;i<2*n;i+=2)ans[2]+=v[i];
 ans[2]+=2*v.back()-v[0];
 for(ll i =3;i<=n;i++){
  ans[i]=ans[i-2]+2*(v[(ll)v.size()-i+1]-v[i-2]);

 }
 for(ll i =1;i<=n;i++)cout<<ans[i]<<" ";

cout<<'\n';}


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
