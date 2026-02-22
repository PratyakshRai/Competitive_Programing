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
   int n; cin>>n;
   vector<pair<int,int>>a;
   for(int i = 0 ;  i < n ; i ++){
    int x,y;cin>>x>>y;
    a.pb({x,y});
   }
   int x1,y1,x2,y2;
   cin>>x1>>y1>>x2>>y2;
   int t=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
   bool ans=true;
   for(int i = 0 ; i < n ; i++){
     int t1 = (a[i].ff-x2)*(a[i].ff-x2)+(a[i].ss-y2)*(a[i].ss-y2);
     if(t>=t1){
      ans=false;break;
     }
   }
   if(!ans){
    NO;
   }else YES;

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