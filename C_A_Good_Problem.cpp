#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
length diya hai n
element ka range diya hai [l,r ]
aur kth smallest element btana hai 
baat ye hai sare element ka & kardo to wo sare element ke xor ke bra bar hona chahiye is  tarah hame elements pick karne hai [l,r]me se 
note element same bhi ho sakte hai 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 pahale ye samjho ki and aur xor same kam honge 

 agar lenght odd hai ,jaise n=1, 3, 5,to ans l hi hoga  


*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
void Chal_Ja_Plz(){
   int n,l,r,k;cin>>n>>l>>r>>k;
   if(n&1){
    cout<<l<<'\n';
    return ;
   }
   if(n==2){
    cout<<"-1\n";
    return ;
   }
   int t=63-__builtin_clzll(l);
   int z=(1LL<<(t+1));
   if(r<z){
    cout<<"-1\n";
    return;
   }
   if(n-k>=2)cout<<l<<'\n';
   else cout<<z<<'\n';

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}