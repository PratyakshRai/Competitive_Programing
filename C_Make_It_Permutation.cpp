/*
Author: Pratyaksh Rai
Date: 2026-02-20
Time: 20:19:53
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
  int n,c,d;cin>>n>>c>>d;
  vi arr(n);
  invec(arr);
  int ans =0;
  map<int,int>mp;
  for(int i=0;i<n;i++){
    mp[arr[i]]++;
  } 
  vi brr;
  for(auto it : mp){

    if(it.ss>1){ans+=(it.ss-1)*c;}
    brr.push_back(it.ff);
  }
  // for(int i:brr)cout<<i<<" ";
  // cout<<endl;
  if(count(brr.begin(),brr.end(),1)==0){
    ans+=d;
    brr.pb(1);
    sort(all(brr));
  }
  int mn=1e18;
  int t=brr.size();
  mn=min(mn,t*c);
  for(int i=t-1;i>=0;i--){
    int to_add=brr[i]-i-1;
    int to_rem=t-1-i;
    mn=min(mn,(to_add*d+to_rem*c));
  }
  cout<<ans+mn<<endl;;
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