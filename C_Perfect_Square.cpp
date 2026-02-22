/*
Author: Pratyaksh Rai
Date: 2026-01-26
Time: 11:25:06
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
        n is even
        is means at every dx layer form the origin the layer must me a palindrome 
        if i somehow obtain the whole onion layer , 
              the layer must be in palindrome 

                  wrong idea , it fails on test case 2 

        har ek element ka comparison uniques nhi hoga
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<string>arr(n);
   for(string &s:arr)cin>>s;
   
   int ans=0;
  for(int layer=0;layer<n/2;layer++){
    vector<char>top,right,bottom,left;
    //top layer 
    for(int i=0+layer;i<n-layer-1;i++){
      top.pb(arr[layer][i]);
    }
    for(int i=0+layer;i<n-layer-1;i++){
      right.pb(arr[i][n-1-layer]);
    }
    for(int i=n-1-layer;i>=layer+1;i--){
      bottom.pb(arr[n-1-layer][i]);
    }
    for(int i=n-1-layer;i>=layer+1;i--){
      left.pb(arr[i][layer]);
    }
    int k=top.size();
    for(int i=0;i<k;i++){
      char chmx=max({top[i],bottom[i],left[i],right[i]});
      ans+=abs(chmx-bottom[i]);
      ans+=abs(chmx-top[i]);
      ans+=abs(chmx-right[i]);
      ans+=abs(chmx-left[i]);
    }
  }
  cout<<ans;
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