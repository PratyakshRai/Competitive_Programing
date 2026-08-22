/*
Author: Pratyaksh Rai
Date: 2026-03-07
Time: 22:14:03
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

          we have a and b  , and the range of a and b 

          what we want is , the number of ordered pairs of (a,b)

          such that (a+b) is a multible of b.gcd(a,b);

          here the ranges for n,m is <= 2e6
                so its clear that , we cant do n^2 
                
          (a+b)=k.b.gcd(a,b);
        
        (a+b)=a*b^2/lcm(a,b);

        what is the range for lcm 
        min(a,b) to a*b 
        what do you mean by lcm ? like it contains the
        common multiples ? right ?
        
        or we can go with gcd only  ? 



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
Always try to optimize your approach
*/
//;'(
int n,m;cin>>n>>m;
int ans =0;
   for(int b=1;b<=m;b++){
    ans+=(n+b)/(b*b);
   }
   cout<<ans-1<<endl;
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