/*
Author: Pratyaksh Rai
Date: 2026-01-11
Time: 13:09:05
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
unordered_set<string>st;
void dp(string s, int n){
if(n==0)return;
  if(st.find(s)==st.end()){
    st.insert(s);
    if(n==1)return;
       dp(s.substr(1),n-1);
    
 

 
    dp(s.erase(1,1),n-1);

  }else return;
}
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s; cin>>s;
  //  cout<<s.erase(1,1)<<endl;
   dp(s,n);
cout<<st.size()<<endl; st.clear();
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) {Chal_Ja_Plz();
   }
    return 0;
}
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/