/*
Author: Pratyaksh Rai
Date: 2026-02-20
Time: 11:14:42
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n' 
#define YES cout << "Yes\n"
#define NO cout << "No\n"
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
int findmex(vector<int>&arr,int n){
  
  vi brr(n);
  for(int i=0;i<n;i++){
    if(arr[i]<n)brr[arr[i]]=1;    
  }
  for(int i=0;i<n;i++){
    if(brr[i]==0){
      return i;
    }
  }
  return n;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
  int n;cin>>n;
  vi arr(n);
  invec(arr);
  int t=findmex(arr,n);
  if(t==0){
    YES;return;
  }
  if(t==n){
    NO;
    return;
  } 

  // cout<<t<<endl;
  int check_int =t+1;
  int freq=0;
  for(int i=0;i<n;i++)if(arr[i]==check_int)freq++;
  if(freq==0||freq==1){
    YES;
    return;
  }
    int mn=n,mx=0;
  for(int i=0;i<n;i++){
    if(arr[i]==t+1){
      mn=min(mn,i);
      mx=max(mx,i);
    }
  }
  for(int i=0;i<n;i++){
    if(i>=mn&&i<=mx)arr[i]=t;
  }
  // cout<<mn<<" "<<mx<<endl;
  // for(int i:arr)cout<<i<<" ";
  // cout<<endl;
  int ne=findmex(arr,n);
  // cout<<ne<<" "<<t+1<<endl;
  if(ne!=t+1)NO;
  else YES;

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