/*
Author: Pratyaksh Rai
Date: 2026-02-25
Time: 12:35:17
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
   vi arr(n),brr(n),final(n);
   invec(arr);
   invec(brr);
   for(int i=0;i<n;i++)final[i]=max(arr[i],brr[i]);
   int first=0,second=0;
   int neg=0,both=0;
   for(int i=0;i<n;i++){
   if(arr[i]==1&&brr[i]==1)both++;
   else if(arr[i]==1&&(brr[i]==0||brr[i]==-1))first++;
   else if (brr[i]==1&&(arr[i]==0||arr[i]==-1))second++;
   else if(arr[i]==-1&&brr[i]==-1)neg++;
    
   }
   int ans=-1e9;
   for(int i=neg;i>=0;i--){
    ans=max(ans,min(first-i,second+both-neg+i));
   }
  for(int i=both;i>=0;i--){
    ans=max(ans,min(first+i,second+both-neg-i));
  }
  cout<<ans<<endl;;
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