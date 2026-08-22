/*
Author: Pratyaksh Rai
Date: 2026-02-27
Time: 17:19:13
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
int n;cin>>n;
   int ans=0;
   vi a(n+1);
   for(int i=1;i<=n;i++)a[i]=i;
   for(int i=0;i<=n;i++){
    vi t=a;
    reverse(t.begin()+i,t.end());
    int curr=0;
    
    int mx=0;
    for(int j=1;j<=n;j++){curr+=t[j]*j;
    mx=max(mx,j*t[j]);

    }
    ans=max(ans,curr-mx);
    
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