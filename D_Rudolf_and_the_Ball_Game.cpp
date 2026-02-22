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
void dp(vector<int>&visited ,vector<pair<int,char>>&arr ,int pos,int i , int n,int &cnt){
  if(i==arr.size())return;
  if(visited[pos]==1)return;
  else {
    visited[pos]=1;
    cnt++;
  
  int d=arr[i].ff;
  if(arr[i].ss=='?'){
    dp(visited, arr,(pos+d)%n,i+1,n,cnt  );
    dp(visited, arr,(pos+n-d)%n,i+1,n,cnt );
  }else if(arr[i].ss=='0'){
  dp(visited, arr,(pos+d)%n,i+1,n,cnt  );
  }
  else {
     dp(visited, arr,(pos+n-d)%n,i+1,n,cnt );
  }
  return;}
}
void Chal_Ja_Plz(){
 int n , m,x;
 cin>>n>>m>>x;
 vector<pair<int,char>>arr;
 for(int i=1;i<=m;i++){
  int r;char ch;
  cin>>r>>ch;
  arr.push_back({r,ch});
 }  
 vector<int>visited(n+1);
 int cnt=0;
 dp(visited,arr,x,0,n,cnt);
 cout<<cnt<<endl;
 for(int i=1;i<=n;i++){
  if(visited[i]==1)cout<<i<<" ";
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