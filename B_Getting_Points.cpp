/*
Author: Pratyaksh Rai
Date: 2026-01-11
Time: 23:35:42
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
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int low=1, high=n;
    int wrk=1e18;
    int P=(n+6)/7;
  
    while(low<=high){
      int mid=low+(high-low)/2;
      int T=min(P,mid*2)*t+mid*l;
      if(T>=p){
        wrk=min(wrk,mid);
        high=mid-1;
      }else low =mid+1;
    }
    cout<<max(0LL, n-wrk)<<endl;
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