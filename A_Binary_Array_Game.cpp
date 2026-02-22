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
alice on 0 wins
bob on 1 wins 

subarray me sare 1 hue to alice hi zeetega
vice versa 

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
   int cnt=count(arr.begin(),arr.end(),1);
   if(cnt==n){cout<<"Alice\n";return;}
   else if(cnt==0){cout<<"Bob\n";return;}
   if(arr[0]==1){
    int mn=1;
    for(int i=1;i<n;i++){
      mn=min(mn,arr[i]);
    }
    if(mn==0){
      cout<<"Alice\n";
    }else cout<<"Bob\n";
   }else if(arr[n-1]==1){
    int mn=1;
    for(int i=0;i<n-1;i++){
      mn=min(mn,arr[i]);
    }
    if(mn==0){
      cout<<"Alice\n";
    }else cout<<"Bob\n";
   }
   else cout<<"Bob\n";

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