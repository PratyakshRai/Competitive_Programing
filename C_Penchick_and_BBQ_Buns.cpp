#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
n buns arranged from left to right , there 10^6 available fillings of bbq buns numbered form 1 to 10 
to insure penchick would love this gift , few goals : 

; no filling is used excatly once , that is each filling must either not appear at all or appear at least twice 
for any two buns i and j , that have the same filling , the distance between them must be a perfect square 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 so atleast 2  ya phir koi filling nhi honi chahiye , aur avilable filling 10^6 hai aur n jo hai wo 2*10^6 hai 
 
 ek baat to clear hai ki hame do ya do se yade filling bharni padegi aur ham sabne unique filling nhi bhar sakte hai 
 for two buns having same filling the distance between them should be perfect square 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 vector<int>seven={1,2,2,3,3,4,4,5,5,1,6,6,7,7,12,12,11,11,10,10,9,9,13,8,8,1,13};
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   if(n%2==0){
    for(int i=1;i<=n;i+=2){
      cout<<i<<" "<<i<<" ";
      
    }
    cout<<"\n";
    return;
   }
   else if (n<27){
    cout<<"-1\n";

   }
   else {
    vector<int>finalanwer=seven;
    int left=n-27;
    for(int i=1,j=14;i<=left;i+=2,j++){
      finalanwer.push_back(j);
      finalanwer.push_back(j);
    }
    for(int i:finalanwer)cout<<i<<" ";
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