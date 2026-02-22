#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
ek ribbon hai jisme n parts kiye gayein hai , ab unparts ko color karna hai ; 

1; pahale alice chalega , aur m me se kisi ek color me se color karega , aur har ek  part ke liye wo koi bhi ek color le sakta hai 

2; bob atmost k part choose karega aur un sabhi ko  repaint karega kisi ek color me   ,

ab alice and bob both play optimally , to ye batao ki ribbon ko ham ek color me paint kar sakte hai ki nhi ? 


hame ye btana hai ki alice ribbon ko kya ayese paint kar payegi ki bob un saro ko ek color dede ? 
ek baar alice chalegi aur ek baar bob

*/
 
// Small Observatins
/*
1: if m==1||n==1: to agar color ie m ek hi rha to no matter alice paint kare ya nhi  , bob wahi paint use karega aur sare same color me ho jayeinge ;



*/
 
 
//Your attacks
/*
 same color kab bansakta hai 


 every part ko alice color karega  ie n parts ko 
 m>=2 
 tab k ko n-1 ke >=hona padega


*/
 
 
// Hints From Code 
/*  


 
*/
 
 

 
 
void Chal_Ja_Plz(){
   int n,m,k;cin>>n>>m>>k;
   int temp=(n-1+m)/m;
   if(k>=n-temp)cout<<"NO\n";
   else cout<<"YES\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}