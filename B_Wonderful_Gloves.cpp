#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 hame ye sochna tha ki wo hamare answer ko defend kaise kar rha hai  , bass usi me answer chhipa tha 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
many gloves are there , each one is one of the n colors numbered 1 to n 
for each i from 1 to n , you will have li left glove and ri right glove 

*/
 
// Small Observatins
/*
97 59 50 87 36
95 77 33 13 74

83 + 100 +36+59+95


192+136+33+13+36

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
   int n,k;cin>>n>>k;
   vector<int>a(n),b(n);
   for(int &i: a)cin>>i;
   for(int &i: b)cin>>i;
   int ans=0;
   
   for(int i=0;i<n;i++){
    ans+=max(a[i],b[i]);
    b[i]=min(a[i],b[i]);
   }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  for(int i=0;i<k-1;i++){
    ans+=b[i];
  }
  cout<<ans+1<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}