#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
you have two integer a and m , count the number of integer y 1<=y<=m such that x!=y and x xor y is a divisor of either x , y or both 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*

x tak to theek hai ham  iterate kardenge 
problem waha hai jaha   y   , x se bda  ho rha hai 
us case me kaise proceed kare ? 

since their xor will always greater than x , so two options will be eliminated , we only have to check for the divisibility for y 
when the xor divides y ;)
that is the major issue , how to find it 

theory1: their can be case where xor will be greater or smaller than y
proved |✅


theory2:  kya xor kabhi divide hi nhi karega  ? 
prove: at least two time to hona chahiye bda otherwise divide hi nhi karega 

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int x ,m ;
   cin>>x>>m;
   int cnt =0;
   for(int i=1;i<=min(2LL*x,m);i++){
    int temp=x^i;
    if(i!=x&&(x%temp==0||i%temp==0))cnt++;
   }
   cout<<cnt<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}