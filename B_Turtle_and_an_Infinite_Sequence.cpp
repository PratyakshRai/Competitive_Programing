/*
Author: Pratyaksh Rai
Date: 2026-02-11
Time: 15:54:42
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
   int n,m;cin>>n>>m;
   int l=max(0LL,n-m);
   int r=m+n;
   int val=1;int ans=0;
   for(int i = 0 ;i < 33; i++){
    if(r-l>=val)ans+=val;
    else if (l&val)ans+=val;
    else if (r&val)ans+=val;
    val*=2;
   }
   cout<<ans<<endl;

  //  for(int i=0;i<40;i++){
  //   if(i==0)cout<<(i|i+1)<<" ";
  //   else {
  //     int t=(i-1)|i;
  //     t=t|(i+1);
  //     cout<<t<<" ";
  //   }
   
  //  } cout<<endl;
  //  if(m==0){
  //   cout<<n<<endl;return;
  //  }
  //  if(n==0){
  //   if(m==1)cout<<1<<"\n";
  //   else cout<<3<<"\n";
  //   return;
  //  }
  //  n++;
  //  int t=63-__builtin_clzll(n);
  //  t++;
  //  t=(1LL<<t)-1;
  //  t=t|n;
  //  cout<<t<<endl;
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