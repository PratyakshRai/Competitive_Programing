#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
A aur M do log hai  jo ki V ko ek problem de rhe hai 

n, k, x  diya jayega 
ab hame ye btana hai ki n me se k distinct number choose kare aur unka sum x ho 


*/
 //Your attacks
/*
x ka range kaise aayega ? 

to  k  distinct no  chahiye ;

to end ke lagatar k no liya to x ki max value 
aur starting ke lagatar liya to x ki min value

prove ye karna hai ki max aur min ke beech koi bhi value le sakte hai ki bhi   , agar ke prove ho gya to  ham given x ko dekhlenge ki wo range me hai ki nhi 


*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
int sum(int n){
  return (n*(n+1))/2;
}
 
 
void Chal_Ja_Plz(){
   int n,k,x;cin>>n>>k>>x;
   int mn=sum(k);
   int mx=sum(n)-sum(n-k);
   if(x>=mn&&x<=mx)cout<<"YES\n";
   else cout<<"NO\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}