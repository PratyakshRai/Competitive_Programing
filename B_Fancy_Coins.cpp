/*
Author: Pratyaksh Rai
Date: 2026-03-24
Time: 20:01:17
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

      make a purchase with cost of exactly m burles 

      two types of coin is there , in the following quantity

            coins worth 1 burle : a1 regular coin and infinitely many fancy coins 

            coins worth k burle : ak regular coin and infinitely many fancy coins 


            total worth of provided coins is exactly m 

            he can use both regular and fancy coins 

            he wants to spend as little as possible 

            what is the smallest total possible fancy coins he can use to make purchase ? 





*/

// Small Observatins
/*

*/
//Your attacks
/*

      a1 aur ak ko ayese smartly use kro ki  no of fancy coins kam hoye 



*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int m, k , a1, ak;cin>>m>>k>>a1>>ak;
   if(a1>=m){
    cout<<"0\n";return;
   }
   m=m-k*(min(ak,m/k));
   if(a1>=m){
    cout<<"0\n";return;
   }
   int F=m/k;
   int f=m-(m/k)*k;
   int t=min(a1,f);
   a1=a1-t;
   f=f-t;
   int T=min(F,a1/k);
   a1-=T*k;
   F-=T;
   cout<<F+f<<endl;
   
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