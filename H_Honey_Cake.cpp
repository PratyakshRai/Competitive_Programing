/*
Author: Pratyaksh Rai
Date: 2026-01-19
Time: 09:47:45
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
  int W,H,D;cin>>W>>H>>D;
  int n;cin>>n;
  for(int i=1;i*i<=n;i++){
    if(n%i!=0)continue;
    int t=n/i;
    for(int j=1;j*j<=t;j++){
      if(t%j!=0)continue;
      int f=t/j;
      vector<vector<int>>arr={{i,j,f},{i,f,j},{j,i,f},{j,f,i},{f,i,j},{f,j,i}};
      for(auto &p:arr){
        int x=p[0],y=p[1],z=p[2];
      

      if(x<=W&&y<=H&&z<=D){
        if(W%x==0&&H%y==0&&D%z==0){
          cout<<x-1<<" "<<y-1<<" "<<z-1<<"\n";
          return;
        }
      }}
    }
  }
  
  cout<<"-1\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; t=1;
    while (t--) Chal_Ja_Plz();
    return 0;
}
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/