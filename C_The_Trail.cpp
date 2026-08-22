/*
Author: Pratyaksh Rai
Date: 2026-03-02
Time: 22:55:48
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
  int n, m;cin>>n>>m;
  string s; cin>>s;
  vector<vector<int>>a(n ,vector<int>(m));
  for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
  vector<int>r(n);
  vector<int>c(m);
  for(int i=0;i<n;i++){
    int sum =0;
    for(int j=0;j<m;j++)sum+=a[i][j];
    r[i]=sum;
  } 
  for(int i=0;i<m;i++){
    int sum =0;
    for(int j=0;j<n;j++)sum+=a[j][i];
    c[i]=sum;
  }
  int cnt=0;
  int x=0,y=0;
  while(cnt<n+m-1){
    if(s[cnt]=='D'){
      a[x][y]-=r[x];
      r[x]+=a[x][y];
      c[y]+=a[x][y];
      x++;
    }
    else{
      a[x][y]-=c[y];
      r[x]+=a[x][y];
      c[y]+=a[x][y];
      y++;
    }
    cnt++;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cout<<a[i][j]<<" ";
    cout<<endl;
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