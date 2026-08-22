/*
Author: Pratyaksh Rai
Date: 2026-02-24
Time: 14:22:50
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
  int n,q;cin>>n>>q;
  vi arr(n);
  invec(arr);
  vi zero(n+1),one(n+1);
  vi dbl(n+1);
   for(int i=0;i<n;i++){
    if(arr[i]==0)zero[i+1]=1;
    else one[i+1]=1;
   }
   for(int i=0;i<n;i++)zero[i+1]+=zero[i];
   for(int i=0;i<n;i++)one[i+1]+=one[i];
   for(int i=1;i<n;i++){
    dbl[i]=dbl[i-1]+(arr[i]!=arr[i-1]);
   }
   
   while(q--){
    int l,r;cin>>l>>r;
    int o=(one[r]-one[l-1]);
    int z=(zero[r]-zero[l-1]);
    if((one[r]-one[l-1])%3){
      cout<<"-1\n";continue;
    }
    if((zero[r]-zero[l-1])%3){
      cout<<"-1\n";continue;
    }
    int sum=(o+z)/3;
    if(dbl[r-1]-dbl[l-1]==(r-l))sum++;
    cout<<sum<<endl;
   }
   
  
  //  for(int i:dbl)cout<<i<<" ";
  //  cout<<endl;
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