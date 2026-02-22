#include<bits/stdc++.h>
using namespace std;

 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek x integer diya gya hai , x>=2 

if there is a positive integer y such that 
1. y<x 
2. 

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
   int x ;cin>>x;
   for(int i=0;i<31;i++){
    int y=0;
    int bit =(1<<i)&(x);
    if(bit!=0){
      y=y|(1<<i);
      for(int j=0;j<31;j++){
        bit=(1<<j)&(x);
        if(bit==0){
          y=y|(1<<j);
          if(y<x){
            cout<<y<<"\n";
            return;
          }
        }
      }
    }
   }
   cout<<"-1"<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}