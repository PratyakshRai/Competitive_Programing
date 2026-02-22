/*
Author: Pratyaksh Rai
Date: 2026-01-18
Time: 13:44:51
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
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   set<int>st;
   int ans=0;
  //  vi pos(n+1);
  //  for(int i=0;i<n;i++){
  //   pos[arr[i]]=i;
  //    }
  //    for(int  k=1;k<n;k++){
  //     if(pos[k]>pos[k+1])ans++;
  //    }
   for(int i =0;i<n;i++){
    int x=arr[i];
    if(st.find(x-1)==st.end()){
      ans++;
      st.insert(x);
    }
    else st.insert(x);
   }
   cout<<ans-1<<endl;
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