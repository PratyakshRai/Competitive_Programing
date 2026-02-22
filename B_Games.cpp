#include <bits/stdc++.h>
using namespace std;



// ------------------- Macros ---------------------


// ------------------- Debugger -------------------

// ------------------- Solve Function -------------
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),brr(m);
    for(int i =0;i<n;i++)cin>>arr[i];
    for(int i =0;i<m;i++)cin>>brr[i];
    int i=0,j=0;
    int x=0,y=0;
    while(i<n&&j<m){
      if(arr[i]>brr[j]){
        j++;
        y++;
        
      }
      else if(arr[i]<brr[j]){
        i++;x++;
      }
      else {
        i++;j++;
      }
    }
while(i<n){
  i++;x++;
}
while(j<m){
  j++;y++;
}
if(x>y){
  cout<<2*min(x,y)+2;
}
else {
  cout<<2*min(x,y)+1;

}cout<<'\n';
    

}

// ------------------- Main Function --------------
int main() {

    int t = 1;
    cin >> t;  // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
