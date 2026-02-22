#include <bits/stdc++.h>
using namespace std;

// ------------------- Typedefs -------------------
#define int long long


// ------------------- Debugger -------------------
#ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ", _print(x)
#else
    #define debug(x...)
#endif


bool can(int H, vector<int>& u, vector<int>& d, int x, int n) {
    int l = H - d[0];
    int high = u[0];
    if (l > high) return false;

    for (int i = 1; i < n; i++) {
        l = max(l - x,H - d[i] );
        high = min(high + x,u[i] );if (l > high) return false;
        // early break
    }  
    return (l<=high);
}

// ------------------- Solve Function -------------
void solve() {
   int n, x;
   cin>>n>>x;
   vector<int>u(n),d(n),sum(n);
   for(int i=0;i<n;i++){
    cin>>u[i]>>d[i];
    sum[i]=u[i]+d[i];
   }
   int low=0;
  int high = *min_element(sum.begin(), sum.end());
int best=0;
   while(low<=high){
    int mid=low+(high-low)/2;
    if(can(mid,u,d,x,n)){
      low=mid+1;
      best=mid;
    }
    else{
      high=mid-1;
    }
   }
   int toatalsum=0;
   for(int i=0;i<n;i++)toatalsum+=sum[i];
   cout<<toatalsum-n*best<<endl;


    

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

    return 1LL*0;
}
