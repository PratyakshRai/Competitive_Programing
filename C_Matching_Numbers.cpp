/*
Author: Pratyaksh Rai
Date: 2026-03-27
Time: 12:36:22
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

       u are given an array of n integers 
       pair the integers 1 to 2n , 
       each integer should be in exactly one pair so that each sum of matched pairs is consecutive and distinct 



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
if(n%2==0){
    NO;return;
}
YES;
vector<pair<int,int>>ans(n);
for(int i=1;i<=n;i++){
    ans[i-1]={i,0};
}
int idx=0;
for(int i=2*n;i>n;i-=2){
    ans[idx++].ss=i;
}
for(int i=2*n-1;i>n;i-=2){
    ans[idx++].ss=i;
}
for(auto it :ans){
    cout<<it.ff<<" "<<it.ss<<endl;
}
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