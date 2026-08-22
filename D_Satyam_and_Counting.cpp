/*
Author: Pratyaksh Rai
Date: 2026-03-08
Time: 21:15:46
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

        we are given n distinct points on 2D 
        it is given that all the points are lie in first quad 

        how many non degenarate triangle can we form ? 
        and the triangle should be right angled ? 


*/

// Small Observatins
/*
      it is mentioned that y is limited and is between 0 and 1 

      rigth angle must satisfies  , and the degeneracy also 

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
   int n,ans=0;cin>>n;
   map<pair<int,int>,int>mp;
   vector<int>cnt(2);
   for(int i = 0 ;i< n;i++){
    int x,y;cin>>x>>y;
    mp[{x,y}]++;
  cnt[y]++; 
  }
  for(auto &[i,j]:mp){
    auto [x,y]=i;
    if(mp.count({x,1-y}))ans+=cnt[y]-1;
    if(mp.count({x+1,1-y})&&mp.count({x-1,1-y}))ans++;
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