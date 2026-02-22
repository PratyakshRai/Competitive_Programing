#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
ek corridor hai jo ki infinitely extended hai right me 
room 1 se start karna hai aur room k ko proceed karna hai aur phir room 1 ko return karna hai , ham k ki value ko choose kar sakte hai moving to adjacent room takes 1 sec 

n traps hai corridor me , ith traph room di me laga hai
us room me enter karne par wo trap activate ho jayega si second me , aur ek baar activate ho gya to us room me na enter kar sakte ho ya exit . determine the maximum vaule of k;

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 di ko sort karne se fayda? 
 trap ke active hone ke baad agar ham ghoom kar ustrap tak pahuch gye to .. 
 activation time ke hisaab se kitna aage bad sakte hai wo hai min(si/2 ; floor value lena)

 ab k ki value kaise save kare ? 
 index save karlo jisme min change ho rha hai
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<pair<int,int>>arr;
   for(int i=0;i<n;i++){
    int d,s;cin>>d>>s;
    arr.push_back({d,s});
   }
   sort(arr.begin(),arr.end());
   int prev=INT_MAX;
  for(int i=0;i<n;i++){
    if(prev<arr[i].first){
      break;
    }
    int temp;
    if(arr[i].second%2==0){
      temp=arr[i].second/2 -1;
    }
    else temp= (arr[i].second/2);
   
    int distance=temp+arr[i].first;
   if(distance<prev){
    prev=distance ;
   }
  }
  cout<<prev<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}