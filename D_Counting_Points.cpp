/*
Author: Pratyaksh Rai
Date: 2026-04-04
Time: 18:15:07
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
#define setbits(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
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
int sqr(int n){
  int root =sqrt(n);
  while((root)*(root)<=n)root++;
  while((root*root)>n)root--;
  return root ; 
}
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
   int n,m;cin>>n>>m;
   vi x(n);
   vi r(n);
   invec(x);
   invec(r);
   map<int,int>mp;
  for(int i=0;i<n;i++){
    for(int curr=x[i]-r[i];curr<=x[i]+r[i];curr++){
      int base=(x[i]-curr)*(x[i]-curr);
      int rr=r[i]*r[i];
      int a=sqr(rr-base);
      mp[curr]=max(mp[curr],a);
    }
  }
  int ans=0;
  for(auto it :mp){
    ans+=it.ss*2+1;
  }
  cout<<ans<<endl;

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