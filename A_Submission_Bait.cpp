#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*


*/
 
// Small Observatins
/*
a is first
who can not operate looses 
mx=0 first 


some function to do : 
choose ai>=mx  
set mx to ai 
ai to 0

matlab mx bad rha hai har baar
to agar hame samne wale to harana hai to ai ko max select karna hoga 

uske baad ye dekhna hoga ki wo max kitni baar aaya hai array me 

alice wins it max is 1, 3, 5, ..



*/
 
 
 
/*
 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(51,0);
   
   for(int i=0;i<n;i++){
   int temp;cin>>temp;
   arr[temp]++;
  
   }
 
   for(int i =0;i<51;i++){
    if(arr[i]%2==1){cout<<"YES\n";
    return;}
   }
cout<<"NO\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}