#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
oddly specific requirement 

a string s is give , contains p ,s , and . , 
determins whether a permutation of lenght n exists such that for all integer i


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 p end se start hona chahiye 
 wo bhi sare p , contigeous p at the end 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s ;cin>>s;
   if(s[0]=='s')s[0]='.';
   if(s[n-1]=='p')s[n-1]='.';
   bool fndP=false ;
   bool fndS=false;
   for(char c: s){
    if(c=='p')fndP=true;
    if(c=='s')fndS=true;
   }
   cout<<((fndP&&fndS)? "NO": "YES")<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}