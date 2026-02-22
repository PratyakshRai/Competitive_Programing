/*
Author: Pratyaksh Rai
Date: 2026-01-21
Time: 16:49:18
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
        for degeneracy 
        a+b>c 
        also 
        a+c>b
        b+c>a


        
        clain : let {}=2^ai 
        so we should have atleast two same numbers also 
        the third no can be smol as possible , and should not be large more than the difference of one
        
        now refine the question : 
        we have three stick  , select three of same size if there freq is more than 3 , ie nc3
        and after select two of them by nc2 , and use it with previous all those sticks
        more over you can use till stick+1 , but it can be covered if there will be the chance of that stick 

        */
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   map<int,int>mp;
   for(int i=0;i<n;i++){
    int temp;cin>>temp;
    mp[temp]++;
   }
  int prev=0;
  int ans=0;
  for(auto it : mp){
    int cnt=it.ss;
    if(cnt>=3)ans+=cnt*(cnt-1)*(cnt-2)/6;
    if(cnt>=2)ans+=(cnt*(cnt-1)/2)*prev;
    prev+=cnt;
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