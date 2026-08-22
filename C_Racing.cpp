/*
Author: Pratyaksh Rai
Date: 2026-02-24
Time: 22:41:18
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

      when it is impossible to jump  ? 
       
      if the h+1 <l
      
      it possible , we have to make greedy 
      decisions , so that h+1<l condition never
      occurs in future
       
      can we maitain minium of the jumps 
      from the back side 



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
   vi arr(n);invec(arr);
   vector<pair<int,int>>lr;
   for(int i=0;i<n;i++){
    int l,r;cin>>l>>r;
    lr.pb({l,r});
   }
   vi rev(n);
   rev[n-1]=(lr[n-1].ss);
   for(int i=n-2;i>=0;i--){
    rev[i]=(min(rev[i+1],lr[i].ss));
   }
  vi ans;
  int h=0;
  for(int i=0;i<n;i++){
    int t=h;
    if(arr[i]==-1||arr[i]==1)t=h+1;
    if(t<lr[i].ff){
      // for(int f:ans)cout<<f<<" ";
      // cout<<"  ";
      // for(int f:rev)cout<<f<<" ";
      
      // cout<<" )";
      cout<<"-1\n";return;
    }
    if(t<=lr[i].ss&&t<=rev[i]){
      if(arr[i]==-1||arr[i]==1){
      ans.pb(1);
      h++;}else ans.pb(0);
    }else {
      ans.pb(0);
    }
  }
   for(int i:ans)cout<<i<<" ";
  //  cout<<" "<<h;
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