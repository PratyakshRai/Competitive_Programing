#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 bool isvalid(int x,int y,int n,int m){
  return (x<n&&x>=0&&y<m&&y>=0);
 }
 
void Chal_Ja_Plz(){
   int n,m;cin>>n>>m;
   vector<vector<int>>arr(n,vector<int>(m));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cin>>arr[i][j];
   }
   int dx[]={1,-1,0,0};
   int dy[]={0,0,1,-1};
   vector<int>b(n*m+1);
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      b[arr[i][j]]=max(b[arr[i][j]],1LL);
      for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(isvalid(x,y,n,m)){
          if(arr[i][j]==arr[x][y])b[arr[i][j]]=2;
        }
      }
    }
   }
   int ans =0;
   for(int i:b)ans+=i;
   ans-=*max_element(b.begin(),b.end());
   cout<<ans<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}