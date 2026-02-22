#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
you have an array of zeros of length n 
 and you can perform two types of operation 

 choose an index i at which ai should be zero and assign 1 to ai 
 choose a pair of index id l and r l<=r al =1 and ar=1 

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
   int ans=1;
   int cur=1;
   for(;;){
      if(cur>=n){
      cout<<ans<<"\n";return;
    }
    cur=cur*2+2;
    ans++;
    if(cur>=n){
      cout<<ans<<"\n";return;
    }
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