/*
Author: Pratyaksh Rai
Date: 2026-02-24
Time: 16:39:58
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
      p and s given 

        p is the prefix gcd 
        
        s is the suffix gcd 
  
  p and s is given 
  detemine if any possible array or not ? 

   
  what does p do ? 
      this is the p 
      (a1) , (a1, a2)  ,(a1,a2, a3 ) 

      what will s do ? 

      (a1,a2,a3) , (a1, a2 ), (a3)

      take it large
      1 2 3 4 5 
      1  1,2  1,2,3  1,2,3,4  1,2,3,4,5

      1,2,3,4,5  2,3,4,5  3,4,5  4,5  5


    see the obervation 






*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n;cin>>n;
vi arr(n),brr(n);
invec(arr);
invec(brr);
if(arr[n-1]!=brr[0]){
  NO;return;
}
for(int i=n-1;i>=1;i--){
  if(arr[i-1]%arr[i]!=0){
    NO;return;
  }
}
for(int i=0;i<n-1;i++){
  if(brr[i+1]%brr[i]!=0){
    NO;return;
  }
}
int check=brr[0];
for(int i=0;i<n-1;i++){
  int g=gcd(arr[i],brr[i+1]);
  // cout<<g<<" ";
  if(g!=check){
    NO;return;
  }
} YES;

  
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