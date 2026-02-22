/*
Author: Pratyaksh Rai
Date: 2026-01-13
Time: 18:45:19
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
    gcd hai , to minimum case lenge  , 
    a aur a except a!=1
    is par linear inequality check karenge aur a ko max value par rakh denge , 
    
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int a, b;cin>>a>>b;
   if(a==b){
    if(a<=3){
      cout<<"-1\n";
    }else {
      cout<<a/2<<" "<<a/2<<endl;
    }
    return;
   }
   int t=(a+1)/2;//ceil value lol
   if(t<=(b/2)){
    t=b/2;
    if(t==1)cout<<"-1\n";
    else cout<<t<<" "<<t<<endl;
   }else cout<<"-1\n";
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