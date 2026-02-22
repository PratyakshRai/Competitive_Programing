/*
Author: Pratyaksh Rai
Date: 2026-02-09
Time: 20:01:48
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
    ek fix no of customer ke liye kitne col bannenge ye dekhna tha , aur wo ceil values se  aayega , lol 
*/
// Hints From Code 
/*  

*/
bool can (vector<int>&arr, int k ,int m){
  int t=0;
  
  for(int i=0;i<arr.size();i++){
    t+=max(arr[i],0LL);
    if(t>=m*k)return true;
  }
  return (t>=m*k);
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,k;cin>>n>>k;
   vi arr(n);
   invec(arr);
   sort(all(arr));
   int l=0;
   int h=1e15;
   int maxval=*max_element(all(arr));
   int sum=accumulate(arr.begin(),arr.end(),0LL);
   while(l<=h){
    int m=l+(h-l)/2;
    if(sum<=m*k&&m>=maxval){
      h=m-1;
    }else l=m+1;
   }
   cout<<l<<endl;
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