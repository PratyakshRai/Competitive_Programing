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
bool cmp(const pair<pair<int,char>,int> &a,
         const pair<pair<int,char>,int> &b){
  if(a.ff.ff!=b.ff.ff)return a.ff.ff<b.ff.ff;
  return a.ss>b.ss;
}
void Chal_Ja_Plz(){
    string s ;cin>>s;
    int n =s.size();
    vector<pair<pair<int,char>,int>>arr;
    arr.push_back({{0,'('},0});
    for(int i=1;i<n;i++){
      int t=arr.back().ff.ff;
      if(s[i-1]=='('){t+=1;
        arr.push_back({{t,s[i]},i});}
      else {
        t-=1;
         arr.push_back({{t,s[i]},i});}
    
      }

   sort(arr.begin(),arr.end(),[](const auto &a, const auto & b){
    if(a.ff.ff!=b.ff.ff)return a.ff.ff<b.ff.ff;
    return a.ss>b.ss;
   });
   for(auto i: arr)cout<<i.ff.ss;

    
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; t=1;
    while (t--) Chal_Ja_Plz();
    return 0;
}
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/