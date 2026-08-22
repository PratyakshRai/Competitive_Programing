/*
Author: Pratyaksh Rai
Date: 2026-03-05
Time: 23:01:18
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

        a array with length n ,  m +ve int 
        string of commands of length n 
        each command is either character L or R 





*/

// Small Observatins
/*

*/
//Your attacks
/*
    what is the problem , overflow ?
    even __int128 can save this righ? 
    how should i optimize it 
    where should i focus on ? 

    a*b*c*d)%m==a%m*b%m*c%m*d%m)%m
    if we do it in reverse ,overflow will never occur 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n ,m;cin>>n>>m;
  vi a(n);
  invec(a);
  int l=0,r=n-1;
  string s;cin>>s;
  vi f;
  for(char ch: s){
    if(ch=='L'){f.pb(a[l]);l++;}
    else {
      f.pb(a[r]);r--;
    }
  }
  vi ans;
  int product=1;
  for(int i=n-1;i>=0;i--){
    product=(product*f[i])%m;
    ans.pb(product);
  }
  reverse(all(ans));
  for(int i: ans)cout<<i<<" ";
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