#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
three thread hai aur ek scissors
kisi bhi time pe ek thread ko lo aur do alag alag hisso me kat do ,  (0,1), (4.3,2.3) ye nhi hona chahiye 


tumhe atmost three operation perform karne hai , aur ye btana hai ki end me jo bhi thread millega kya wo sare equal length ka mill payega ? 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 agar ham ye proof karne ki koshish nhi ki kab no aayega to shayad kaam ban jaye
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*
question ko observer nhi kiya , ek do teen hisso me todne par kya hoga
reverse engineering type shit to ki thi but thoda chuk gya 



*/
 
 
void Chal_Ja_Plz(){
   int a,b,c;
   cin>>a>>b>>c;
   int  g=gcd(a,b);
   g=gcd(g,c);
int mn = min(a, min(b, c));
   if(a==b&&b==c&&c==a){
    cout<<"YES\n";
    return;
   }

  if(a%mn!=0||b%mn!=0||c%mn!=0){
    cout<<"NO\n";
    return;
  }
  else {
    int temp=(a/mn)+(b/mn)+(c/mn);
    if(temp<=6)cout<<"YES\n";
    else cout<<"NO\n";
  }


   }
  
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}