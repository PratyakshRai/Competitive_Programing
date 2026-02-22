#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
agar k>1 hai to 
if n==1 then check divisibility for 11 otherwise no is the answer 
if k==1 
then normal do prime check 

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 bool  checkprime(int n){
  if(n==1)return false;
  for(int i=2;i*i<=n;i++){
    if(n%i==0)return false;
  }
  return true;
 }
void Chal_Ja_Plz(){
  int n,k;cin>>n>>k;
 if(n==1){
  string s=string(k,'1');
      int x=stol(s);
      if(checkprime(x)){
        cout<<"YES\n";
      
      }else {
        cout<<"NO\n";
      }
      return;
 }
 if(checkprime(n)&&k==1){
  cout<<"YES\n";
 }else cout<<"NO\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}