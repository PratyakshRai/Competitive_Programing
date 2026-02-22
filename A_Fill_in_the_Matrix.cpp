/*
Author: Pratyaksh Rai
Date: 2026-02-18
Time: 20:35:55
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

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,m;cin>>n>>m;
   vector<vector<int>>arr(n,vector<int>(m,0));
   int mx=min(m,n);
   if(n<m){
    mx=n+1;
   }
   if(m==1&&n>1)mx=0;
   else if(m==1&&n==1)mx=0;
   
  int req=min(n,m-1);
   for(int i=0;i<req;i++){
    for(int j=0;j<m;j++){
      arr[i][j]=(m-1-i+j)%m;
    }
   }
   for(int i=req;i<n;i++){
    arr[i]=arr[0];
   }
   cout<<mx<<endl;;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cout<<arr[i][j]<<" ";
    cout<<endl;
   }
   cout<<endl;;
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