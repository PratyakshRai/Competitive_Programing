/*
Author: Pratyaksh Rai
Date: 2026-02-06
Time: 13:19:20
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
            let suppose you got the strig of particular layer
            you wanna iterate over the string , 
            when even you find 1 , while(s[(i+p)%n]==p[i])i++ and if p==3 cnt++;

            how to iterate through the layer? 
            layer to n-layer-1
            n and m is even :) layer=min(n/2, m/2)

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n , m;cin>>n>>m;
  vector<string>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  int la=min(n/2, m/2);
  string r;
  int cnt=0;
  for(int layer=0;layer<la;layer++){
 r="";
    //top
    for(int i=layer;i<m-layer-1;i++){
        r+=arr[layer][i];
    }
    for(int i=layer;i<n-layer-1;i++){
        r+=arr[i][m-layer-1];
    }
    for(int i=m-layer-1;i>layer;i--){
        r+=arr[n-layer-1][i];
    }
    for(int i=n-layer-1;i>layer;i--){
        r+=arr[i][layer];
    }
 string t = "1543";
if (r.size() >= 3) {
    r = r.substr(r.size() - 3) + r;
}

for(int i = 0; i + 4 <= r.size(); i++){
    if(r.substr(i, 4) == t){
        cnt++;
    }
}
    // cout<<r<<endl;
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