/*
Author: Pratyaksh Rai
Date: 2026-02-11
Time: 21:19:42
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
    d(distinct elements ) should be the subset of b
*/
// Hints From Code 
/*  
3
4 1 2
3 4 2
3
3 4 4
*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n;cin>>n;
vi arr(n),brr(n);
invec(arr);
invec(brr);
int m  ;cin>>m;
vi drr(m);
map<int,int>mp;
for(int i=0;i<m;i++){
  int x;cin>>x;
  mp[x]++;
  drr[i]=x;   
}
int cnt=0;
map<int,int>cmp,Drr,C;
for(int i=0;i<n;i++){
  {
    cmp[brr[i]]++;
   
  }
  if(arr[i]!=brr[i]) {cnt++;C[brr[i]]++;}
  
}
 for(auto it : C){
  int val=it.ff;
  int freq=it.ss;
  if(mp.find(val)==mp.end()){
    NO;return;
  }
  if(mp[val]<freq){
    NO;return;
  }
 }
if(cmp.find(drr[m-1])==cmp.end()){
 NO;return;
}
 
YES;
 
 
   
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