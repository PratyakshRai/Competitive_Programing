#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
teen deck of cards hai , first deck me a , b, c cards hai , a<b<c 


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
   int a,b,c;cin>>a>>b>>c;
   int temp=a+b+c;
   if(temp%3!=0){
    cout<<"NO\n";return;
   }
   temp=temp/3;
   int give =c-temp;
   if(give<0){cout<<"NO\n";return;}
   if(a>temp||b>temp){
    cout<<"NO\n";return;
   }
   if(2*temp-a-b>give){
    cout<<"NO\n";
   }else cout<<"YES\n";


}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}