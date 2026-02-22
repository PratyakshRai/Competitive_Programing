#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
 n sheeps hai , ith has a beauty of ai all ai are distinct 


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 max of gcd(a,b)is max of(a,b )where one is the divisor of other 
 
 we have to just take two number , let x and y 
 then take x+t , and y+t 
 if(x+t)%y+t==0 
 

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   int mx=-1;
   int mn=1e9+5;
   for(int i=0;i<n;i++){
    int temp;cin>>temp;
    mx=max(mx,temp);
    mn=min(mn,temp);
   }
   int ans=mx-mn;
  
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