#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array aur ek integer x diya gya hai 
you can perform following operation : 
select two adjacent element and replace with some integer y 

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
   int mn=1e9;
   int mx=-1e9;
   for(int i=0;i<n;i++){
    int temp;cin>>temp;
    mx=max(mx,temp);
    mn=min(mn,temp);
   }
   int t;cin>>t;
   if(t>=mn&&t<=mx)cout<<"YES\n";
   else cout<<"NO\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}