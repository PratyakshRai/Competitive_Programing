/*
Author: Pratyaksh Rai
Date: 2026-03-25
Time: 23:13:25
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
  vi a(n+1);
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i =1;i<=n/2;i++){
    int idx=i;
    vector<pair<int,int>> s;
    vi indexes;
   while(idx<=n){
    if(idx<=n){s.pb({a[idx],idx});indexes.pb(idx);}
    idx=2*idx;
   }
   sort(all(indexes));
  //  if(idx<=n)s.pb({a[idx],idx});
   sort(all(s));
   for(int k=0;k<s.size();k++){
    a[indexes[k]]=s[k].ff;
   }


  }
  // for(int i:a)cout<<i<<" ";
  // cout<<endl;

  // vi b;
  // for(int i=1;i<=n/2;i++)b.pb(a[i]);
  // for(int i=n/2+1;i<=n;i++){
  //   if(i%2==0)b.pb(a[i]);
  // } 
  // sort(all(b));
  // int idx=0;
  // for(int i=1;i<=n/2;i++)a[i]=b[idx++];
  // for(int i=n/2+1;i<=n;i++){
  //   if(i%2==0)a[i]=b[idx++];
  // }
  // for(int i:a)cout<<i<<" ";
  // cout<<endl;
  if(is_sorted(all(a))){
    YES;
  }
  else NO;
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