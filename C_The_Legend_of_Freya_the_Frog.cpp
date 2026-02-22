#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
directions alternative hai , like pahale  x phir y phir x phir y ..... ie  x y x y x y ..
minimum amount of moves to reach at point x,y? 

ceil of x/k and y/k 
then take max of ceil of x/k and  y/k 

11 , 9   (3)


(3,0), (3,3),(6,3),(6,6),(9,6),(9,9),(11,9)

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
 int  floor_div(int  a, int  b) {
     if (b < 0) a = -a, b = -b;   // denominator ko positive karo
     if (a >= 0) return a / b;
     return -((-a + b - 1) / b);
 }
 
 int  ceil_div(int  a, int  b) {
     if (b < 0) a = -a, b = -b;
     if (a >= 0) return (a + b - 1) / b;
     return -((-a) / b);
 }
 
void Chal_Ja_Plz(){
   int  x,y,k;cin>>x>>y>>k;
  
   int t1=ceil_div(x,k);
   int t2=ceil_div(y,k);
   int ans=max(t1,t2);
  ans*=2;
   if(t1>t2)ans--;
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