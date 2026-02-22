#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
do array di gayi hai , A and  B  which contains n and m elements respectively 
for  integer i =1 to n  he is allowed to perform at most once the following operations 

ek integer j lo aur ai=bj-ai;

we have to tell weather this guy can sort the array or not 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 mai sare elements ko change karunga bhale hi wo accending me hai ya na 
 kaise: to smallest as possible 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n,m;cin>>n>>m;
  vector<int>arr(n),brr(m);
  for(int &i:arr)cin>>i;
  for(int &i:brr)cin>>i;
  sort(brr.begin(),brr.end());
  int previous =-1e18;
  for(int i=0;i<n;i++){
    bool flag=false;
    int temp=2e18,t=2e18;
    if(arr[i]>=previous)temp=arr[i];
   for(int j=0;j<m;j++){
    
    
    if(brr[j]-arr[i]>=previous){
      t=brr[j]-arr[i];
      
      break;
    }}
    previous=min(temp,t);
    if(previous==2e18){
      flag=false;
    }else flag=true;
    
   
   if(!flag){
    cout<<"NO\n";return;
   }
  }
  cout<<"YES\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}