#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
(n + 1)x(n + 1) grid di gayi hai  whose cooordinates are pair of integers from 0 to n ;

do log game khel rhe hai , A and B 
A  ka goal hai ki wo B se pakda  na jaye jitni deer tak , 
jabki B ka goal hai wo A ko pakad le jitna jaldi 

A kab pakda jayega  , jab A aur B same cell me honge 

ab alternate pattern me dono chalenge , pahale A chal rha hai phir B , 

A kaise chalega ? : -
1. yato wo same cell me rhe , ya to move kare vertically ya horzontally ek unit , jaise (a-1,b),(a,b-1).. diagonally nhi move kar sakte ;

2. B kaise chalega ? : - 
1. A ki tarah hi hai , bas ye diagonally extra chal sakta hai 

do no player grid ke bahar nhi ja sakte 

ab A ka survival time : no of B turns until it catches A 

ab maanlo do no optimally khe rhe hai to A ka survival time kya hoga ? 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
inka manhattan distance >=1 hona chahiye ;
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*

k bhagega aur d pakdega 
ab dono ke beech ka relative distance par focus karna tha 
ek distance dx hoga aur ek distance dy me hoga 
ab k ko bhagna hai , (x+1 ,y),(x,y+1);
ab isme d ek ek kar karke pass ayega , agar aur dx aur dy me se ek zero kar dega 

*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   int kr,kc,dr,dc;
   cin>>kr>>kc>>dr>>dc;
   if(kr==dr&&kc==dc){
    cout<<1<<"\n";
    return;
   }
  int ans=0;
  int dx=abs(kc-dc);
  int dy=abs(kr -dr);
  int x=(kc>dc?n-kc:kc);
  int y=(kr>dr?n-kr: kr);
  if(dx==0||dy==0){
    if(dx==0)ans=max(0*1LL,dy+y);
    else ans=max(dx+x,0*1LL);
    cout<<ans<<"\n";return;
  }
  ans=max(dx+x,dy+y);
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