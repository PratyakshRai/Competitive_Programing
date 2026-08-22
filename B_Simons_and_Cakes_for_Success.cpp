/*
Author: Pratyaksh Rai
Date: 2026-02-26
Time: 20:15:32
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
  map<int,int>mp;
  for(int i=2;i*i<=n;i++){
    if(n%i==0)mp[i]++;
    while(n%i==0){
      n/=i;
    }
   

  }
  if(n>1)mp[n]++;
  int ans=1;
// for(auto  it :mp)cout<<it.ff<<" ";
// cout<<endl;
// for(auto it :mp)cout<<it.ss<<" ";
// cout<<endl;
  for(auto it : mp)ans*=it.ff;
  cout<<ans<<endl;

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // prime[0]=prime[1]=1;
//  for(int i=2;i*i<=N;i++){
//   if(prime[i]==0){
//     for(int j=i*i;j<=N;j+=i){
//       prime[j]=1;
//     }
//   }
//  }
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