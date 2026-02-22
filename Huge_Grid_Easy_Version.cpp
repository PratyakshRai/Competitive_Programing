#include <bits/stdc++.h>
using namespace std;
#define int long long
// ------------------- Typedefs -------------------
typedef long long ll;
int dp(vector<vector<int>>&arr,vector<vector<int>>&memo,int i, int j,int n){
  if(i>n||j>n)return 2e15;
  if(i==n&&j==n)return arr[i][j];
  if(memo[i][j]!=-1)return memo[i][j];
  int dis=arr[i][j];
  int right=dp(arr,memo,i,j+1,n);
  int left=dp(arr,memo,i+1,j,n);
  return memo[i][j]=dis+min(left,right);
}

// ------------------- Solve Function -------------
void solve() {
    int n ;
    string s;
    cin>>n>>s;

    vector<vector<int>>arr(n,vector<int>(n,0));
     vector<vector<int>>memo(n,vector<int>(n,-1));
    vector<int>pref(n+1,0);
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        pref[i+1] = pref[i] + digit;
    }
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    if(i<=j){
      arr[i][j]=pref[j+1]-pref[i];
    }
    else arr[i][j]=arr[j][i];
  }
}
int ans=dp(arr,memo, 0,0,n-1);
cout<<ans<<endl;


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
