#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array diya gya hai  a    , n integer hai 

for every integer k from 1 to n , 


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 5 8 10 13 13 14 15 

13 13 13 14 14 15 15
15 14 13 13 10 8 5
15 15 14 14 13 13 13 
13 28 36 50 60 65 78

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int & i:arr)cin>>i;
   vector<int>b;
   int mx=-1;
   int sum =0;
   vector<int>pre;
   for(int i: arr){
    mx=max(mx,i);
    b.push_back(mx);
   }
   for(int i=n-1;i>=0;i--){
    sum+=arr[i];
    pre.push_back(sum);
   }
  for(int i=0;i<n;i++){
    if(i==0){
      cout<<b[n-i-1]<<" ";
    }else {
      cout<<b[n-i-1]+pre[i-1]<<" ";
    }
  }

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