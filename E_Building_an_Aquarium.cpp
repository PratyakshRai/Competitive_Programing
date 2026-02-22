/*
Author: Pratyaksh Rai
Date: 2026-01-13
Time: 18:22:24
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
int bs(vector<int>&arr,int n, int h){
  int result=0;
  for(int i=0;i<n;i++){
    result+=max(0LL,h-arr[i]);
  } 
  return result;
}
void Chal_Ja_Plz(){
  int n,h;cin>>n>>h;
  vi arr(n);
  invec(arr);
int mx = *max_element(arr.begin(), arr.end());
int low = 0, high = mx + h;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(bs(arr,n,mid)<=h){
      low=mid+1;
    }else high=mid-1;
  } 
  cout<<high<<endl;
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