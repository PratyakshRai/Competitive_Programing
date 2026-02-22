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
 void f(int r, int c , int n, int val , vector<vector<int>>&ans){
  if(ans[r][c]!=-1)return;
  ans[r][c]=val--;
  while(c+1<n&&ans[r][c+1]==-1)ans[r][++c]=val--;
  while(r+1<n&&ans[r+1][c]==-1)ans[++r][c]=val--;
  while(c>0&&ans[r][c-1]==-1)ans[r][--c]=val--;
  while(r>0&&ans[r-1][c]==-1)ans[--r][c]=val--;
  f(r,c+1,n,val,ans);
 }
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<vector<int>>ans(n,vector<int>(n,-1));
   f(0,0,n,n*n-1,ans);
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
   }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}