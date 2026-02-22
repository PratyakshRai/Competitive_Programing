#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
n<=20 
types A or B 

type A: decrease x by x--;
type B: replace x with floor x=x/2;


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 mai pahale se hi ek full round ka equation bna ke rakhlunga prefix sum typo shit 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n,q;cin>>n>>q;
   string s;cin>>s;
   int b=count(s.begin(),s.end(),'B');

   while(q--){
    int u;cin>>u;
    if(b==0){
      cout<<u<<"\n";
      continue;
    }
    int cnt=0;
    int i=0;
    while(u>0){
      if(s[i]=='A')u--;
      else u/=2;
      i=(i+1)%n;
    cnt++;}
    cout<<cnt<<"\n";
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