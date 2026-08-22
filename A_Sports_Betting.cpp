/*
Author: Pratyaksh Rai
Date: 2026-03-13
Time: 00:16:13
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

      we have all the permutations with one elment missing 
      and we dont  know which element it is 

      the order is unknown 


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
vector<vector<int>>s(n);
for(int i = 0 ; i < n  ; i++){
  for(int j=0;j<n-1;j++){
    int x;cin>>x;
    s[i].pb(x);
  }
}
set<int>st;
for(int i=0;i<n;i++)for(int j=0;j<n-1;j++)st.insert(s[i][j]);
vector<string>a(n);
for(int i=0;i<n;i++){
  string temp="";
  for(int j=0;j<n-1;j++)temp+=s[i][j]+'0';
  a[i]=temp;
}
for(int i=0;i<n;i++){
  
}
   
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