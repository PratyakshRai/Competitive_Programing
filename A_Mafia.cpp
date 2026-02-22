#include <bits/stdc++.h>
using namespace std;

// ------------------- Typedefs -------------------
#define int long long 
bool can(int mid , int sum , int n){
  return mid*(n-1)>=sum;
}
// ------------------- Solve Function -------------
void solve() {

  int n; 
  cin>>n;
  vector<int>arr(n);
int mx=0;
int sum=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    mx=max(arr[i],mx);
    sum+=arr[i];
  }
int low=mx, high=sum;
while(low<=high){
  int mid=low+(high-low)/2;
  if(can(mid, sum ,n)){
    high=mid-1;
  }
  else low=mid+1;
}
cout<<low;
    

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
