#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
initially n different types of magincal material diya gya hai 
ai unit of material i for each i 
you are allowed to perform operation : 
select a material then spend 1 unit of every other material j to gain 1 unit of material i ; 


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
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   int neg=0;
   int give=1e9;
   int req=0;
   for(int i=0;i<n;i++){
    int b;cin>>b;
    if(b<=arr[i])give=min(give, arr[i]-b);
    else {
      neg++;
      req=b-arr[i];
    }
   }
   if(neg>1){
    cout<<"NO\n";
    return;
   }
   else if(req<=give){
    cout<<"YES\n";return;
   }else cout<<"NO\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}