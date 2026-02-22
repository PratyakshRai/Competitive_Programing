#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
n coins forming a circle 
alice goes first 

operation : 
ek player facing up coin ko uthayega aur aur htadega  , uske adjacent two coin ko flip kar dega 
agar do coin hai to ek hata do aur dusare ko flip karne ki jarurat nhi hai, aur agar ek hi coin bcha hai to usko flip karne ka koi matlab nhi 
if there is no facing up coins , the player will lose 





game will end in a finite no of operation 


*/
 
// Small Observatins
/*
cicular array hai , adjacent : (i+1)%n, (i-1+n)%n 


*/
 
 
//Your attacks
/*
 we can do bruite force
 agar ham maximum number of play nikal le to maze hi maze 
 
no of plays <=n;

*/
 
 
// learn from code 
/*  
try observe how to win , in this case if no of u is decreasing  by most of the time and increase only at dud by 1 so if no of u is odd then only alice can win 

kaun kab kaise jeetega ispar focus kro , like is case me agar alice ko jeetna hai to hame kya karna hoga like , to uske like ye dekho alice haregi kaise , jab uske liye no of u zero bcha ho , aur no of u decrease kaise kar rha hai ye pta kro phir ye dekho ki no of plays aur no of u's me kya difference hai , phir jake to answer ayega
 
*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;string s; cin>>s;
   int cnt=count(s.begin(),s.end(),'U');
   if(cnt&1)cout<<"YES\n";
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