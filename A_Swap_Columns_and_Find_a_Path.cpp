#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek matrix diya gya hai 2 row and n col , the rows are numbered from 1 to 2 from top to bottom 
the col are numbered from left to right 
each cell contains ek integer , initially the integer in the cell is aij

you can perform the following operation any number of time 
choose two number like x and y , and swap like , 

like do number lo aur un index pe jo hai unko swap kardo , like 

after performing the operatins you have to choose a path from the cell  1 1 to 2 n , path me yato aage bad sakte ho ya to neeche 
the cost of the path is the sum of all n+1 cells belonging to the path , you have to perform the operations and choose a path so that its cost is maximum possible 

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
   vector<vector<int>>arr(2,vector<int>(n));
   for(int i =0;i<2;i++){
    for(int j=0;j<n;j++)cin>>arr[i][j];
   }
   int sum =0;
   for(int i=0;i<n;i++)sum+=max(arr[0][i],arr[1][i]);
   int mn=-1e9;
   for(int i=0;i<n;i++)mn=max(mn,min(arr[0][i],arr[1][i]));
   cout<<sum+mn<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}