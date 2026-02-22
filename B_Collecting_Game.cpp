/*
Author: Pratyaksh Rai
Date: 2026-01-11
Time: 18:14:59
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
int bs(int i, int n , vector<pair<int,int>>&arr,vector<int>&prefix){
  int low=i+1,high=n-1;
  int result=i;
  int target=prefix[i];
  while(low<=high){
    int mid=low+(high-low)/2;
    if(target>=arr[mid].ff){
      target=prefix[mid];
      result=mid;
      low=mid+1;
    }else {
      high=mid-1;
    }
  }
  return result;
}
void Chal_Ja_Plz(){
  int n;cin>>n;
  vector<pair<int,int>>arr(n);

  for(int i=0;i<n;i++){
    int x;cin>>x;
    arr[i]={x,i};
  }
  sort(all(arr));

  vector<int>prefix(n);
  prefix[0]=arr[0].ff;
  for(int i=1;i<n;i++){
    prefix[i]=prefix[i-1]+arr[i].ff;
  }
  // for(int i: prefix)cout<<i<<" ";cout<<endl;
 vector<int>rechable(n);
 rechable[n-1]=n-1;
 for(int i =n-2;i>=0;i--){
  if(prefix[i]>=arr[i+1].ff){
    rechable[i]=rechable[i+1];
  }else rechable[i]=i;
 }
 vector<int>ans(n);
 for(int i=0;i<n;i++){
  ans[arr[i].ss]=rechable[i];
 }
 for(int i : ans)cout<<i<<" ";
 cout<<endl;

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