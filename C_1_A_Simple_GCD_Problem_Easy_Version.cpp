/*
Author: Pratyaksh Rai
Date: 2026-03-29
Time: 22:26:56
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

    two array are given 

    a and b (n)

    for each index u can perform atleat one operation 

    choose an index m <=ai
    set ai=m 

    after performing all the operations 

    the following conditions holds true

    maximum no of operations that can be performed 


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
int n;cin>>n;
vi a(n),b(n);
invec(a);invec(b);
int prev=-1;
int cnt=0;
for(int i=1;i<n-1;i++){
  int g1=gcd(a[i-1],a[i]);
  int g2=gcd(a[i],a[i+1]);
  if(a[i]>lcm(g1,g2))cnt++;
  
}
int t=gcd(a[n-1],a[n-2]);
if(t==gcd(a[n-2],t)&&t!=a[n-1])cnt++;
t=gcd(a[0],a[1]);
if(t==gcd(a[1],t)&&t!=a[0])cnt++;
cout<<cnt<<endl;
   
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