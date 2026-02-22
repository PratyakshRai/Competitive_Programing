#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*


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
   int a,b,c,d;cin>>a>>b>>c>>d;
  int alicemx=max(a,b);
  int alicemn=min(a,b);
  int bobmax=max(c,d);
  int bobmin=min(c,d);
  if(alicemx<bobmax){
    if(bobmin<alicemn||bobmin>alicemx){
      cout<<"NO\n";
    }else cout<<"YES\n";
  }
  else if(alicemx>bobmax){
    if(alicemn<bobmin||alicemn>bobmax){
      cout<<"NO\n";
    }else cout<<"YES\n";
  }
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