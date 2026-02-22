/*
Author: Pratyaksh Rai
Date: 2026-02-21
Time: 15:13:24
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
garam hai garam hai 
*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
  int n;cin>>n;
  vi arr(n),brr(n);
  invec(arr);
  invec(brr);
   int a=0,b=0,all=0;
   for(int i=0;i<n;i++){
    all^=arr[i];
    all^=brr[i];
   }
   if(!all){
    cout<<"Tie\n";return;
   }
   int bit=0;
   int idx=0;
   for(int i=0;i<20;i++)if(all&1<<i)bit=i;
   for(int i=0;i<n;i++){
    if((arr[i]^brr[i])&1<<bit)idx=i;

   }
   if(idx&1){
    cout<<"Mai\n";
   }else cout<<"Ajisai\n";

  

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