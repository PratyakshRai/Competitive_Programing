/*
Author: Pratyaksh Rai
Date: 2026-02-01
Time: 18:21:10
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
      LxorR should be equal to the xor of all the numbers between them 
      le it is A ie L xor R
      then A = a1^a2^a3^..an;

      then the thing is how to make a number in terms of n number xors ? 
      at max it can be represented by x numbers then after we can make pairs inorder to cancel them 
*/
// Hints From Code 
/*  
    code by tle eliminator ;)
*/
void Chal_Ja_Plz(){
int n, l,r;cin>>n>>l>>r;
vector<int>pr(n+1);
pr[0]=0;
for(int i =1;i<=n;i++){
  if(i==r){
    pr[i]=pr[l-1];
  }else pr[i]=i;
}
for(int i =0;i<n;i++){
  cout<<(pr[i+1]^pr[i])<<" ";}
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