#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
to array diye gaye hai , A aur B  
ek range choose karo i ka , jaise [2,5] aur swap(ai,bi) for all i belongs to [2,5];

ek subset of indices is good if after swapping ,both the arrays are in sorted order
your task to calculate the number of good subsets, 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 atleast do subset to ho ga hi 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*

combinatrics : like brick by brick jod kar banaya hai 
suru se hi pichhla sara combination dekh rha hai

reverse engineering from the answer to the question 


*/
 #define mod 998244353
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>a(n),b(n);
   for(int &i: a)cin>>i;
   for(int &i: b)cin>>i;
   for(int i=0;i<n;i++){
    if(a[i]>b[i])swap(a[i],b[i]);
   }
int ans=2;
  for(int i=0;i<n-1;i++){
if(max(a[i],b[i])<=min(a[i+1],b[i+1])){ans*=2LL;ans%=mod;}

  }
cout<<ans<<"\n";

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}