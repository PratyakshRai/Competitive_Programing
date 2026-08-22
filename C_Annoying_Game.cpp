/*
Author: Pratyaksh Rai
Date: 2026-02-23
Time: 13:58:00
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
  int n,k;cin>>n>>k;
  vi arr(n);
  vi brr(n);
  invec(arr);
  invec(brr);
  int ans=-2e18;
  int curr=arr[0];
  int sec =curr+brr[0];
  int ans1=-2e18;
  ans1=max(curr,ans1);
  ans=max({sec,curr,ans});
  for(int i=1;i<n;i++){
   int t=arr[i]+brr[i];
   sec=max(max(curr+t,t),sec+arr[i]);
  //  int pre=max(curr,arr[i]);
  //  if(pre+t>sec){
  //   sec=curr+t;
  //  }else sec+=arr[i];
    curr=max(arr[i],curr+arr[i]);
   
    ans=max({sec,curr,ans});
    ans1=max(ans1,curr);
  } 
  if(k%2==0){
    cout<<ans1<<endl;
    return;
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