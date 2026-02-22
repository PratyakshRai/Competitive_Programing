/*
Author: Pratyaksh Rai
Date: 2026-01-25
Time: 20:48:49
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n' 
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vi vector<int>
#define ff first
#define ss second
#define invec(v) for(int &i : v) cin >> i;
// Common constants
const int INF = 1e18;
const int MOD = 1e9 + 7;

// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Problem Statement
/*

*/

// Small Observatins
/*

*/
//Your attacks
/*
    nxn matrix is given non negative
    an array a of n elements 


    Mij=ai or with aj , but i!=j like the diagonal
    and Mii=0 and Mij=Mji
    it means it is a symmetric around diagonal
    for the elements in the upper diagonal , 
    condition : i<j ke liye hai 


    it is something like 
            a1|a2 , a1|a3, a1|a4
            a2|a3  , a2|a4
            a3|a4

     now we have to figure out this "or"
     how can we achieve the results ? 
     agar ham matrix se lowest values ko le 
     a1 sab me commom hai , like row 1 me 
     a2 row 2 me  , similarly it goes on .. 
     
     
     if we find all the common elements and then recompute the matrix it should match with the original one 

     to find the common and with all the elements 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   int t=(1LL<<30)-1;
   vector<vector<int>>arr(n,vector<int>(n,0));
   for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>arr[i][j];
   vector<int>ans(n,t);
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        ans[i]&=arr[i][j];
      }
    }
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
      if((ans[i]|ans[j])!=arr[i][j]){
        NO;return;
      }}
    }
   }
    YES;
    for(int i:ans)cout<<i<<" ";
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
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/