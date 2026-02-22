/*
Author: Pratyaksh Rai
Date: 2026-02-12
Time: 21:34:38
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
  vi arr(n);
  invec(arr);
  int ans=0;
  int idx =0;
  int mt=*max_element(all(arr));
  for (int i=0;i<32;i++){
    int t=(1LL<<i);
    if((mt&t)!=0)idx=i;
  }
  // cout<<idx<<endl;
  for(int i=0;i<=idx;i++){
    int t=(1LL<<i);
    int len=0;
    int mx=0;
    for(int k=0;k<n;k++){
      if((t&arr[k])==0)len++;
      else {
        
        len=0;
      }
      mx=max(len,mx);
    }
    
    if(mx==n)mx=0;
    ans=max(mx,ans);
  } 
  // cout<<ans+1<<endl;
  // if(ans==0)
  cout<<min(ans+1,n)<<endl;
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