#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
do log ek saath khelenge , winner ko 2 points aur looser ko 1 point millega, agar draw hua to dono ko ek ek points mille ga 
it is also possible that no games were played at all 

hame maximum no of draw btana hai 

fir un teen logo ne kuch games khele aur khelne ke baad unka score diya gya hai 
if there isn't any way to obtain p1,p2,p3 : -1 cout

*/
 
// Small Observatins
/*
1. agar ek ek point milta rha to koi jeetega hi nhi 


*/
 
 
//Your attacks
/*
 
*/
 
 
// Hints From Code 
/*  
odd all same then -1;
if all are even 0


 
*/
 
 
void Chal_Ja_Plz(){
   int a,b,c;cin>>a>>b>>c;
   if ((a+b+c)%2) {
    cout<<"-1\n";
    return;
   }
   cout<<min((a+b),(a+b+c)/2)<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}