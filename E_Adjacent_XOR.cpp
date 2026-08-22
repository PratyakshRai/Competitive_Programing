/*
Author: Pratyaksh Rai
Date: 2026-02-24
Time: 15:08:59
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
  int n;cin>>n;
  vi arr(n),brr(n); 
  invec(arr);
  invec(brr);
  if(arr[n-1]!=brr[n-1]){
    NO;return;
  }
  for(int i=n-2;i>=0;i--){
    int t1=arr[i]^brr[i+1];
    int t2=arr[i]^arr[i+1];
    if(t1!=brr[i]&&t2!=brr[i]&&arr[i]!=brr[i]){
      // cout<<brr[i]<<" "<<t1<<" "<<t2<<" "<<i<<" ";
      NO;
      return;
    }
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