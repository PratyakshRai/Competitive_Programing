/*
Author: Pratyaksh Rai
Date: 2026-02-04
Time: 21:29:41
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
ai !=0 
       if n = 1 && x = 0 => -1
      
      greedy 1: to minimize the sum we should count the no of ones in it let ones =O
     if x is even 
                if O>=n then ans=x
                if O<=n then ans=x+n-o  , if n-o is odd then ans++;
      if x is odd 
                  if O>=n then ans=x
                  if O<=n then ans=          



*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/

int n ,x;cin>>n>>x;
if(n==1&&x==0){
  cout<<"-1\n";return;
}
if(x==1&&n%2==0){
  cout<<n+3<<endl;return;
}
int O=__builtin_popcountll(x);
if(O>=n){
  cout<<x<<endl;
  return;
}

int ans=x+n-O;
if((n-O)%2!=0)ans++;
if((n-O)%2!=0&&x==0)ans+=2;
cout<<ans<<endl;
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