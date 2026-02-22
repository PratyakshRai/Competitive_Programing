#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
n sticks hai , length hai 1 se n tak , the lengths of sticks are distinct 

in sticks ko kisi order me lgana hai 
ye order ek string btayegi 

agar s[i]= > to i+1 position pe jo stick hai wo 1 se leke i tak ke sare sticks se bda  hoga 
< to chhota hoga 
do number chahiye jinko mai decrease ya increase kar saku


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
   int n;cin>>n;
   string s;cin>>s;
   int inc=count(s.begin(),s.end(),'>');
   int dec=n-inc;
   int incval=n-inc+1;
   int decval=dec-1;
   vector<int>b(n,0);
   int idx=1;
   for(int i=0;i<n-1;i++){
    if(s[i]=='<'){
      b[idx]=decval;
      decval--;
    }
    else {
    b[idx]=incval;
    incval++;


   }
   idx++;
  }
  b[0]=dec;
  for(int i:b)cout<<i<<" ";
  cout<<"\n";
   
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}