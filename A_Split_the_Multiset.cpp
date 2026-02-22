#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*


*/
 
// Small Observatins
/*
multiset is given with positive int

initially multiset me ek hi element rahega  jo ki "n" hai 
we were given a positive integer k also 

operation to do : 
kisi ek +int  ko select kro , aur use hatado , aur <=k no of positive integer dalo , ayese integer choose kro , like jase y choose kiya to sum of all integer is equal to u ;
like 
let suppose hamne y choose kiya to n*y==u && n<=k;


ab hame ye batao ki kitne no of operation lagenge ki ham sare elements 1 ho jaye , like 1 1 1 1 1 1 1 jaise ho jayein; 


solution : 
case 1; agar u<=k hua to ham u times 1 lelenge; 
case 2: if u>k



*/
 
 
//Your attacks
/*
 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
void Chal_Ja_Plz(){
   int n, k;cin>>n>>k;
   if(n==1){
    cout<<0<<endl;
    return;
   }
   int cnt=0;
 while(true){
  if(n<=k){
    cnt++;break;
  }
  n=n-(k-1);
  cnt++;
 }
 cout<<cnt<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}