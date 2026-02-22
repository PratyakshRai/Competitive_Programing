#include <bits/stdc++.h>
using namespace std;
#define int long long 
// ------------------- Typedefs -------------------

bool can(int k , vector<pair<int,int>>&wind, int x2,int y2,int x1,int y1,int n ){
  int fullcycles=k/n;
  int remainingcycle =k%n;
  int cyclex=wind[n].first;
  int cycley=wind[n].second;
  int windx=x1+fullcycles*cyclex+wind[remainingcycle].first;
  int windy=y1+fullcycles*cycley + wind[remainingcycle].second;
  int distance=abs(x2-windx)+abs(y2-windy);
  return distance<=k;


}
// ------------------- Solve Function -------------
void solve() {
    int x1 ,y1,x2,y2,n;
    cin>>x1>>y1>>x2>>y2>>n;
    string s;
    cin>>s;
    vector<pair<int,int>>wind(n+1,{0,0});
    for(int i=0;i<n;i++){
      wind[i+1]=wind[i];
      if(s[i]=='U')wind[i+1].second++;
      if(s[i]=='D')wind[i+1].second--;
      if(s[i]=='L')wind[i+1].first--;
      if(s[i]=='R')wind[i+1].first++;
    }
    
    int low=0;
    int high=2e18;
    int ans =-1;
    while(low<=high){
      int mid=low+(high-low)/2;
      if(can(mid , wind, x2, y2, x1, y1, n)){ans=mid;
        high=mid-1;
        
      }
      else low=mid+1;
    }

    cout<<ans;
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
