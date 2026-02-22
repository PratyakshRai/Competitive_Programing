#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 matlab hame mex ko bdana tha uske liye hame ek ek karne number add karne the aur check karna tha ki ye number jo add kar rhe hai iske sare bits k me hai ki nhi , agar hai to dheere dheere sare numbers add karte jao ,
 isme ek end case bhi aaye ga jisme ham last element ko dekhenge agar last element ke bhi sare bits us x me hai to phir theek hai , last number ko tabhi add karenge jab uske add karne ke baad jo final element bann rha hai  wah x ke equal hai , agar ayesa nhi hai to ham x ko hi jod denge aur hamare mex ki max vaue n-1 tak ho jayegi 
 is question ko mai 1000 se 1300 rating dunga\
 
 actual rating 1200 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*


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



*/
 
 
void Chal_Ja_Plz(){
   int n, k;
   cin>>n>>k;
   vector<int>arr(n,k);
   int o=0;
   bool flag=true;
   for(int i=0;i<n-1;i++){
    if(((o|i)&k)==(o|i)){
      o=o|i;
      arr[i]=i;
    }else {flag=false;
    break;}
   }
   if(flag&&(o|(n-1))==k){
    arr[n-1]=n-1;
   }
   for(int i: arr)cout<<i<<" ";
   cout<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}