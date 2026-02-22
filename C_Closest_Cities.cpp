/*
Author: Pratyaksh Rai
Date: 2026-02-15
Time: 16:49:18
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
   vi arr(n);
   invec(arr);
   vi brr(n);
   int mn=1e9+5;
  //  brr[0]=0;
   for(int i=0;i<n-1;i++){
    if(arr[i+1]-arr[i]<mn){
      brr[i]=1;
    }else {
      brr[i]=arr[i+1]-arr[i];
    }
    mn=arr[i+1]-arr[i];
   }mn=1e9+5;
   vi crr(n);
   reverse(all(arr));
      for(int i=0;i<n-1;i++){
    if(abs(arr[i+1]-arr[i])<mn){
      crr[i]=1;
    }else {
      crr[i]=abs(arr[i+1]-arr[i]);
    }
    mn=abs(arr[i+1]-arr[i]);
   }
  //  for(int i=n-1;i>0;i--){
  //   if(abs(arr[i]-arr[i-1])<mn){
  //     crr[i]=1;
  //   }else {
  //     crr[i]=abs(arr[i]-arr[i-1]);
  //   }
  //  }
   vi pref(n+1),suffix(n+1);
   for(int i=0;i<n;i++)pref[i+1]=pref[i]+brr[i];
   for(int i=0;i<n;i++)suffix[i+1]=suffix[i]+crr[i];
  //  for(int i: brr)cout<<i<< " ";
  //  cout<<"\n";
  //  for(int i : pref)cout<<i<<" ";
  //  cout<<"\n";
  //  for(int i : suffix)cout<<i<<" ";
  int q ;cin>>q;
  while(q--){
    int x,y;cin>>x>>y;
    if(x<y){
      x--;y--;
      cout<<pref[y]-pref[x]<<endl;
    }else{
      x=n-x+1;
      y=n-y+1;
      x--;y--;
      cout<<suffix[y]-suffix[x]<<endl;
    }
  }

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