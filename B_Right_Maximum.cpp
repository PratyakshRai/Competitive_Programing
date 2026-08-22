/*
Author: Pratyaksh Rai
Date: 2026-03-28
Time: 18:33:51
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
There is always a simpler solution for the question 
*/
  int n;cin>>n;
  vi a(n);
  invec(a);
  multiset<int>st;
  map<int,vector<int>>mp;
  for(int i=0;i<n;i++){
    int val=a[i];
    st.insert(val);
    mp[val].pb(i);
  } 
  int cnt=0;
  int smol=2e18;
  while(!st.empty()){
    auto it =prev(st.end());
    int t=*it;
    st.erase(it);
    int last=mp[t].back();
    if(last<smol){
      cnt++;
      smol=last;
    }
    
    if(last==0)break;
    mp[t].pop_back();
  }
  cout<<cnt<<endl;
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