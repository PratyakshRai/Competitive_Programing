/*
Author: Pratyaksh Rai
Date: 2026-01-19
Time: 20:27:34
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
      give array ko sort kardenge 
      phir max leng where each element is greater than zero


      fuck, exactly n time karna hai na ki arbitrary no of  times !
          sum of all element agar N ke barabar hai tb to har ek ko ek ek bar hi kar paoge 
              sum of element agar N se kam to not possible 
              sum of element+1 - N,t ka min vaule

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   int t =count(arr.begin(),arr.end(),0);
   t=n-t;
   int sum=accumulate(arr.begin(),arr.end(),0LL);
   sum++;

   cout<<min(sum-n,t)<<endl;
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