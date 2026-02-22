#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 minimum wali cheej ko nhi pakad paya mai 
 jaise gcd<=minimum 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek sequence diya hai  , determine if it is possible to rearrange that sequence such that the gcd of all number is equal to min(a1,a2,a3...ai)


array ko ayese sufel karo ki , min(a1, to , ai )==gcd(ai+1 to an ) ye possible hoye

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*

3 12 24 


*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   int g=0;
   int mx=min_element(arr.begin(),arr.end())-arr.begin();

   for(int i=0;i<n;i++){
    if(i!=mx&&arr[i]%arr[mx]==0){
      g=gcd(g,arr[i]);
    }
   }
   cout<<(g==arr[mx]?"Yes": "No")<<"\n";

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}