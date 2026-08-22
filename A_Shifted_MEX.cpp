/*
Author: Pratyaksh Rai
Date: 2026-03-02
Time: 12:53:25
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
  vi a;
  for(int i=0;i<n;i++){
    int x ;cin>>x;
  a.pb(x);
  } 
  sort(all(a));
  int cnt=1;
  int ans=0;
  for(int i=0;i<n-1;i++){
      ans=max(ans,cnt);

    if(a[i]+1==a[i+1]){
      cnt++;
    }
    else if (a[i]==a[i+1]){
      continue;
    }
    else {
      cnt=1;
    }
  }
      ans=max(ans,cnt);
      cout<<ans<<endl;
  // int smol=*min_element(all(a));
  // for(int i=0;i<a.size();i++){
  // a[i]-=smol;
  // }
  // int v[a.size()+2]={0};
  // for(int i=0;i<a.size();i++){
  //   v[a[i]]++;
  // }

  // for(int i=0;i<=a.size()+1;i++){
  //   if(v[i]==0){
  //     cout<<i<<endl;
  //     return;
  //   }
  // }
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