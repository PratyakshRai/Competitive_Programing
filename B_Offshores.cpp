/*
Author: Pratyaksh Rai
Date: 2026-02-08
Time: 14:43:41
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
    ab maximize karne ke liye no of transection ko limit karna hoga ie chhote me se bade me dalna ? 
    hame x ka multiple bnana hai 
    the thing is he can transfer only x ruppes at a time 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
maa kasam 
  dont assume ki last pair pe hi saara boojh ayega 
*/
   int n,x,y;cin>>n>>x>>y;
   vi arr(n);
   invec(arr);
  //  vector<pair<int,pair<int,int>>>brr;
  //  for(int i=0;i<n;i++){
  //   brr.pb({arr[i]%x,{arr[i]/x,arr[i]}});
  //  }
  //  sort(all(brr));
  //  for(int i=0;i<n-1;i++){
  //   brr[n-1].ss.ss+=brr[i].ss.ff*y;
  //  }
  //  cout<<brr[n-1].ss.ss<<endl;
  int cnt=0;
  for(int i=0;i<n;i++){
    cnt+=(arr[i]/x)*y;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    ans=max(ans,(cnt-(arr[i]/x)*y)+arr[i]);
  }
  cout<<ans<<endl;

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