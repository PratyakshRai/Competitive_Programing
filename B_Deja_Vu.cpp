/*
Author: Pratyaksh Rai
Date: 2026-01-13
Time: 12:55:27
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
    mereko add bhi karna hai aur phir array badal jayegi , like update ho jagi , phir nai array me check karna hai 

*/

// Small Observatins
/*

*/
//Your attacks
/*
agar mai 2^5 add karwata hu to 2^4 nhi add karwa paunga , LOL:)

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n,q;
   cin>>n>>q;
   vi arr(n);
   vi brr(q);
   invec(arr);
   invec(brr);
   int prev=60;
   int ans=0;
   for(int i=0;i<q;i++){
    if(prev>=brr[i]){
      
      int div=(1LL<<brr[i]);
     int cnt=0;
      for(int j=0;j<n;j++){
        if(arr[j]%div==0){arr[j]+=(1LL<<(brr[i]-1));}
      }
     
prev=brr[i]-1;
      
     
    }
   }
   for(int i:arr)cout<<i<<" ";
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