#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
initially ek array di gayi hai aur all elements are red in color  , you have to choose exactly k elements of the array and paint them blue , then while there is at least one red element you have to select with blue neighbour and make it blue 


matlab hame maximum possible cost chahiye


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
   int n,k;cin>>n>>k;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;

  if(k>1){   sort(arr.begin(),arr.end()); int c=0;
   for(int i=n-1;i>=n-(k+1);i--){
    c+=arr[i];
   }
   cout<<c<<"\n";}
   else {
     int l = *max_element(arr.begin(), arr.end() - 1);
      int r = *max_element(arr.begin() + 1, arr.end());
      int ans =max(l+arr.back(),r+arr[0]);
    cout<<ans<<"\n";
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