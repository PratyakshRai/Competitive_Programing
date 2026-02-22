#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek purmutation construct karna hai n length ka 
whre pi + pi+1 composite hona chahiye 


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
   if(n<5){
    cout<<"-1\n";
    return;
   }
   for(int i=1;i<=n;i+=2){
    if(i!=5)cout<<i<<" ";
   }
   cout<<"5 4 ";
   for(int i=2;i<=n;i+=2){
    if(i!=4)
    cout<<i<<" ";
   }
   cout<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}