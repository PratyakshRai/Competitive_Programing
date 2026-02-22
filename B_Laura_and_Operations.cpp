#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
kuch digit likhegayein hai , jo ki 1, 2, 3 se bne hai  
1 ki sankhya a , 2 ki b aur  3 ki c hai 

operation : 
do different digit lena hai , kahi se bhi aur unge erase kardena hai phir ek different digit unse different hona  chahiye , add kar dena hai , ab hame ye btana hai ki  
at the end board pe kya ek tarah ka digit bach jayega ki nhi ? 


*/
 
// Small Observatins
/*

same rha to 1 1 1 ans hoga 
2nd bda aur 3rd bda dono yato odd ho yato even ; tabb bde par 1 ayega 

*/
 
 
//Your attacks
/*
 gcd lcm hcf 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
  int a,b,c;cin>>a>>b>>c;
  if(abs(a-b)%2==0&&abs(b-c)%2==0){
    cout<<"1 1 1";
  }
  else if(abs(a-b)%2==0&&abs(b-c)%2!=0){
    cout<<"0 0 1";
  }else if (abs(a-b)%2!=0&&abs(b-c)%2==0){
    cout<<"1 0 0";
  }else  if(abs(a-c)%2==0&&abs(a-b)%2!=0){
    cout<<"0 1 0";
  }else cout<<"0 0 0";
  cout<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}