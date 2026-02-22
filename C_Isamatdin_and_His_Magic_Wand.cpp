#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 question theek se nhi pda tha , question bahut simple tha 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
a ke paas n toys hai  - ith toy has an integer ai, he wanted to sort them 

we can only swap two integer iff both have different parity

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 larger ko end me bhejna hai aur smaller ko aage lana hai
 simple swap karne se to ho jayega par , kitne iteration me kaam chalega 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>a(n);
   
   for(int &i:a){
    cin>>i;
  }
  bool flag=true;
  for(int i=0;i<n-1;i++){
    if(abs(a[i]-a[i+1])%2!=0)flag=false;
  }
  if(flag){
    for(int i:a)cout<<i<<" ";
    cout<<'\n';
  }
  else {
    sort(a.begin(),a.end());
    for(int i:a)cout<<i<<" ";
    cout<<"\n";

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