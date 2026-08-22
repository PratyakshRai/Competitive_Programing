/*
Author: Pratyaksh Rai
Date: 2026-02-28
Time: 21:24:57
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
  vi a(n);
  invec(a);
  int prev=-1;
  // for(int i=0;i<n-1;i++){
  //   cout<<gcd(a[i],a[i+1])<<" ";
  // } 
  // cout<<endl;
  int idx=-1;
  int cnt=0;
  for(int i=0;i<n-1;i++){
    int t=gcd(a[i+1],a[i]);
    if(t<prev){
      idx=i;
      break;
    }
    
      prev=t;
      // break;
    
    // cout<<prev<<" ";
  }  
  if(idx==-1){
    cout<<"YES\n";return;
  }
 vector<vector<int>>b(3);
  for(int i=0;i<n;i++){
    if(i!=idx-1)b[0].pb(a[i]);
    if(i!=idx)b[1].pb(a[i]);
    if(i!=idx+1)b[2].pb(a[i]);

  }
  vector<vector<int>>gc(3);
  for(int i=0;i<b[0].size()-1;i++){
    gc[0].pb(gcd(b[0][i],b[0][i+1]));
    gc[1].pb(gcd(b[1][i],b[1][i+1]));
    gc[2].pb(gcd(b[2][i],b[2][i+1]));
  }
  if(is_sorted(all(gc[0]))||is_sorted(all(gc[1]))||is_sorted(all(gc[2]))){
    cout<<"YES\n";
  }
  else {
    cout<<"NO\n";
  }
  // for(int i=0;i<gc[0].size()-1;i++)cout<<gc[2][i]<<" ";
  // cout<<endl;
  // cout<<idx<<endl;
  // cout<<endl;
  // cout<<cnt<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    int i=1;
    while (t--) {Chal_Ja_Plz();i++;}
    return 0;
}
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/