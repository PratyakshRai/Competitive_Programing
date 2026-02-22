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
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   int sum =accumulate(arr.begin(),arr.end(),0LL);
   if(sum %n!=0){
    cout<<"NO\n";return;
   }
   int cmp=sum/n;
  int odd=0,even =0;
  for(int i=0;i<n;i+=2){
    odd+=arr[i];
  }
    for(int i=1;i<n;i+=2){
    even+=arr[i];
  }
  if(odd%((n+1)/2)!=0||even%(n/2)!=0){
    cout<<"NO\n";return;
  }
  if(odd/((n+1)/2)!=cmp||even/((n/2))!=cmp){
    cout<<"NO\n";return;
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