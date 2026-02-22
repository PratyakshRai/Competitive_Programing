#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 question samajh me hi nhi aaya 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
there is list n booleans which is either 0 or 1 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 to ham like 1 aur 0 ko 1 bna sakte hai or kar ke aur , bob 0 aur 1 ko 0 bna sakta hai 
 ek zero kitna khayega ? 
 alice ke chalne ke baad ? 

 ek zero 2 one khayega 
 like ek zero ko khatam karne ke liye hame atleast 

 bob kya kar sakta hai ki no of zero badaye , aur alice  no of zero kam kre 


 bob ya alice koshish karenge ki 01 ya 10  mille 

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s;cin>>s;
   int z=count(s.begin(),s.end(),'0');
   int one=n-z;
   z--;
   if(z<one){
    cout<<"YES\n";
   }
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