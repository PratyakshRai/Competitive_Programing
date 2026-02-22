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
   int n,k;cin>>n>>k;
   if(n==1&&k==1){
    cout<<"1\n";
    cout<<"1\n";
    return;
   }
   if(k==1||k==n){
    cout<<"-1\n";
    return;
   }
   if(k%2==0){
    cout<<"3\n";
    cout<<1<<" "<<k<<" "<<k+1<<"\n";
    return;
   }
   if(k<3||k>n-2){
    cout<<"-1\n";
    return;
   }
   cout<<"5\n";
   cout<<1<<" "<<k-1<<" "<<k<<" "<<k+1<<" "<<k+2<<"\n";
   return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}