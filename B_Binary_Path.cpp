/*
Author: Pratyaksh Rai
Date: 2026-02-14
Time: 20:27:33
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
   vector<string>s(2);
   cin>>s[0]>>s[1];
   string mn="";
   bool flag=true;
   int drop=n-1;
   for(int i=0;i<n-1;i++){
    if(s[0][i+1]>s[1][i]){
      drop=i;
      break; 
    }
   }
   for(int i=0;i<=drop;i++){
    mn+=s[0][i];
   }
   for(int i=drop;i<n;i++){
    mn+=s[1][i];
   }
   int cnt=1;
  int idx = mn.size() - 1;
  
   for(int i=drop;i>0;i--){
   
    if(s[0][i]==s[1][i-1])cnt++;
    else break;
  
   }
   cout<<mn<<endl;
   cout<<cnt<<endl;
  //  cout<<mn<<endl;
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