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
   for(int i=0;i<n;i++)cin>>arr[i];
   sort(arr.begin(),arr.end());
   int mx=0;
   for(int i=0;i<n;i+=2){
    if(max(mx,arr[i])!=max(mx,arr[i+1])){
      cout<<"No\n";
      return;
    }
    mx=max(arr[i],mx)+1;
   }
   cout<<"Yes\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}