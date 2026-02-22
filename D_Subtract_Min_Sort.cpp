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
    for(int i=0;i<n-1;i++){
      int mn=min(arr[i],arr[i+1]);
      if(arr[i+1]==mn&&arr[i]!=mn){
        cout<<"NO\n";return;
      }
      arr[i+1]-=mn;

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