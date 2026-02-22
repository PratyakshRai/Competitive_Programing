/*
Author: Pratyaksh Rai
Date: 2026-02-11
Time: 09:11:19
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
/*
Always try to optimize your approach
*/
   int N;cin>>N;
   vi arr(N);
   invec(arr);
   int mn=1e9;
   int mx=-1e9;
   int c=0;
   int ans=0;
   int n=0,m=0;
   for(int i=0;i<N;i++){
    int a=arr[i];
    int x1=n+a;
    int x2=abs(n+a);
    int x3=m+a;
    int x4=abs(m+a);
    int nn=min({x1,x2,x3,x4});
    int mm=max({x1,x2,x3,x4});
    n=nn;
    m=mm;
    ans=(max(abs(n),abs(m)));
   }
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