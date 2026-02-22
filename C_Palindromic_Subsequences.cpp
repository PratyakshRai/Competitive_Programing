#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
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
   int n;cin>>n;
   vector<int>v(n);
   if(n==6){
    cout<<"1 1 2 3 1 2\n";return;
   }
   else if (n==7){
    cout<<"1 1 2 3 1 2 2\n";
    return;
   }else {
    for(int i=0;i<n/2;i++){
      v[i]=i+1;
    }
    for(int i =n/2;i<n;i++){
      v[i]=i-n/2+1;
    }
   }
   for(int i:v)cout<<i<<" ";
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