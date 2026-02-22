#include<bits/stdc++.h>
using namespace std;

 
#define ll long long 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek permutation diya hai of length n ;
if perfect if sum of first i element of that is not a perfect square ;



like suru se le karke i tak ke index ka sum ek perfect square nhi hona chahiye 

yani prefix sum ke array me kahi bhi perfect square nhi aana chahiye 

*/
 
// Small Observatins
/*

perfect square number ko kabhi bhi i =1 pe nhi rakhna hai

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
 bool isq(ll n){
    return ceil(sqrtl(n))==floor(sqrtl(n));
 }
 
void Chal_Ja_Plz(){
   ll n ;
   cin>>n;
   if(isq(n*(n+1)/2)){
    cout<<-1<<"\n";
    return;
   }
   vector<ll>arr;
   vector<ll>brr(n);
   for(int i=0;i<n;i++){
    brr[i]=i+1;
   }
   ll p1=0;
   arr.reserve(n);
   ll sum =0;
   for(int i=0;i<n;i++){
    if(isq(sum+brr[p1])){
        arr.push_back(brr[p1+1]);
        brr[p1+1]=brr[p1];
        p1++;
    }
    else {
        arr.push_back(brr[p1]);
        p1++;
    }
    sum+=arr.back();
   }
   for(auto x : arr){
    cout<<x<<" ";
   }
   cout<<endl;
   return;


}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}