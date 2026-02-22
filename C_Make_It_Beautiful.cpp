#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek number ki beauty us number ke no of one bit in its binary representation me  , btata hai 

hame ek array di gayi hai : 
array ki beauti sum of beauties of numbers it contains ,btata hai 

ab atmost k operation me ham array ki max beauti btani hai

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 agar even rha to ek jod denge , to beauti bdegi hi har haal me 
 even rha to ek bda denge;
 odd wale ko end me dekhenge , 

 even me bit invest karne ke baad let set hmare paas x more operation bach gye hai 
 ab odd ho gaye hai sare cases

 problem kya hai , kis odd ko bdau hai kitna bdau? 

 sort kardiya maine 

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n,k;cin>>n>>k;
   vector<int>arr(n);
   int ans=0;
   for(int &i: arr){
    cin>>i;
    ans+=__builtin_popcountll(i);
   }
   for(int i=0;i<=60;i++){
    int b=(1LL<<i);
    for(int x:arr){
      if(!(x&b)&&k>=b){
        ans++;
        k-=b;
      }
    }
   }
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