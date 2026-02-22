#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 jaldbaazi kari , easy question tha , core logic pe focus karna tha like avg kab badega jab usse jade bda number add kiya jaye; aur avg utha hi rhega
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
subarray sum maximum btana hai 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 prefix sum bna liya maine maanlo 
 jo ki hai: 

 0,7,8,14,23,32


*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   int mx=-1;
   for(int i=0;i<n;i++){
    int temp;cin>>temp;
    mx=max(mx,temp);
   }
   cout<<mx<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}