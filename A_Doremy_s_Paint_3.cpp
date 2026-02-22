/*
Author: Pratyaksh Rai
Date: 2026-02-17
Time: 13:31:34
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n' 
#define YES cout << "Yes\n"
#define NO cout << "No\n"
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
   map<int,int>mp;
   for(int i=0;i<n;i++){
    int x;cin>>x;
    mp[x]++;
   }
   if(mp.size()>2){
    NO;
    return;
   }
   else if (mp.size()==1){
    YES;
    return;
   }
   for(auto it :mp){
    int fre=it.ss;
    if(fre>(n+1)/2){
      NO;return;
    }
   }
   YES;
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