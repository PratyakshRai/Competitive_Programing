#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
we have to minimize the A-B

 so bob can increase some of the scores of the array so that we can decrease the A-B values 
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
   int n , k;cin>>n>>k;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   int ans =0;
   sort(arr.begin(),arr.end(),greater<int>());
 for(int i=0;i<n-1;i+=2){
  int temp=min(arr[i],arr[i+1]+k);
  if(temp==arr[i]){
    k-=arr[i]-arr[i+1];
  }
  else{
    ans+=arr[i]-arr[i+1]-k;
    k=0;
  }
 }
 if(n%2==1){
  ans+=arr[n-1];
 }
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