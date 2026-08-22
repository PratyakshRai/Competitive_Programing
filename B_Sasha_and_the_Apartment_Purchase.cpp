/*
Author: Pratyaksh Rai
Date: 2026-04-03
Time: 20:04:13
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
#define setbits(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define invec(v) for(int &i : v) cin >> i;
// Common constants
const int INF = 1e18;
const int MOD = 1e9 + 7;

// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Problem Statement
/*


      h are numbered from 1 to 10^9

      there are n bars located in houses with ai number 

      there might be multiple bars in the same house 


      no more than k bars  can be closed  , bars in the same house 
      are condidered as distinct 

      x let the house no , 
      f(x) as the sum of |x-y| , where y is the open 
      bars , ie after closing some bars 







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
There is always a simpler solution for the question 
*/
int n,k;cin>>n>>k;
vi a(n);
invec(a);
sort(all(a));
int left=(n-k-1)/2;
int right =n-1-left;
cout<<a[right]-a[left]+1;
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