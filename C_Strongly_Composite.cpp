/*
Author: Pratyaksh Rai
Date: 2026-02-19
Time: 20:56:33
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
const int M=1e7+4;
int prr[M];
vector<bool>ispr(M,true);
void save(map<int,int>&mp,int x){
  int i=2;
  while(i*i<=x){
    if(prr[i]){
    while(x%i==0){
      x=x/i;
      mp[i]++;
    }
  }
  i++;
  }
  if(x>1)mp[x]++;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
  int n;cin>>n;
  vi arr(n);
  invec(arr); 
  map<int,int>mp;
  for(int i=0;i<n;i++){
    save(mp,arr[i]);
  }
  int cnt=0;
  int ans=0;
  for(auto it:mp){
    int freq=it.ss;
    if(freq%2!=0)cnt++;
    ans+=freq/2;
  }
  if(cnt==2&&ans==0){
    cout<<"0\n";
    return;
  }
  ans+=cnt/3;
  cout<<ans<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ispr[0]=ispr[1]=false;
    for(int i=2;i*i<M;i++){
      if(ispr[i]){
        for(int j=i*i;j<M;j+=i)ispr[j]=false;
      }
    }
    for(int i=2;i<M;i++)if(ispr[i])prr[i]=1;
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