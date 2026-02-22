/*
Author: Pratyaksh Rai
Date: 2026-02-17
Time: 17:02:54
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
  int n,q;cin>>n>>q;
  vi arr(n),brr(n);
  invec(arr);
  invec(brr);
  vi mx(n);
  int mxx=-1;
  for(int i=n-1;i>=0;i--){
    int m=max(arr[i],brr[i]);
    if(mxx<m)mxx=m;
    mx[i]=mxx;
  }
  for(int i=0;i<n-1;i++){
    arr[i]=max({arr[i],mx[i],brr[i]});
  } 
  arr[n-1]=max(arr[n-1],brr[n-1]);
  vi prefix(n+1);
 for(int i=0;i<n;i++)prefix[i+1]=prefix[i]+arr[i];
 while(q--){
  int l,r;cin>>l>>r;
  l--;r--;
  cout<<prefix[r+1]-prefix[l]<<" ";
 }
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