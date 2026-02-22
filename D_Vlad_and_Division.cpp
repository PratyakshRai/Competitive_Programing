/*
Author: Pratyaksh Rai
Date: 2026-02-15
Time: 16:32:11
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
  int c=(1LL<<31)-1;

  map<int,int>mp;
  for(int i=0;i<n;i++){
    mp[arr[i]]++;
  } 
  int ans=n;
  for(int i=0;i<n;i++){
    int complement=c-arr[i];
    if(mp[arr[i]]>0&&mp[complement]>0){
      ans--;
      mp[arr[i]]--;
      mp[complement]--;
    }
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