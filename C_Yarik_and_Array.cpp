/*
Author: Pratyaksh Rai
Date: 2026-01-12
Time: 20:46:05
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
  int n;cin>>n;
  vi arr(n);
  invec(arr);
  int ans=-1e9;
  int maxsum=arr[0];
  int currsum=arr[0];
  for(int i=1;i<n;i++){
    if(abs(arr[i])%2==abs(arr[i-1])%2){
      currsum=0;
    }
    currsum=max(arr[i],currsum+arr[i]);
    maxsum=max(maxsum,currsum);
  }
 
 cout<<maxsum<<endl;
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