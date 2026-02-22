#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array hai a1, a2, a3, a4 ..an
dusari array hai b1,b2,b3..bm


matlab ek array dijayegi , uska ek sequence ka length btao  jo kisi dusare array ke sequence ke product , sab same ho 



*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*

do element hai , x,y 
unka product same hai 
xy=k manlo 
 

same element nhi le sakte hai , to set bnalo 



*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   set<int>arr;
   for(int i=0;i<n;i++){
    int temp;cin>>temp;
    arr.insert(temp);
   }cout<<arr.size()<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}