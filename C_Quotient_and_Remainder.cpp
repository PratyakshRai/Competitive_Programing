/*
Author: Pratyaksh Rai
Date: 2026-02-01
Time: 20:57:54
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
  int n , k;cin>>n>>k;
  vi q(n),r(n);
  invec(q);
  invec(r);
  sort(all(q));
  sort(all(r));
  int ans=0;
  int i=0;int j=n-1;
  while(i<n&&j>=0){
    int p=r[j];
    p++;
    if(p>k){j--;continue;}
    int c=p*q[i]+(p-1);
    if(c<=k){ans++;i++;j--;}
    else j--;
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