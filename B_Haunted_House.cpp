/*
Author: Pratyaksh Rai
Date: 2026-01-13
Time: 16:29:10
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
zero ka distance end se , 
subs both the position of , ie one's and zero's  , then find the first zero after it 
the total no of zero is the postion till we can have the divisions
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n ;cin>>n;
   string s;cin>>s;
   s="#"+s;
   int record=0;
   int zero=count(s.begin(),s.end(),'0');
   vector<int>ans;
   int zindx=n;
   for(int i=n;i>=n-zero+1;i--){
    while(zindx>=1&&s[zindx]=='1')zindx--;
    record+=i-zindx;
    zindx--;
    ans.pb(record);

   }
   for(int i:ans)cout<<i<<" ";
   for(int i=0;i<n-ans.size();i++)cout<<"-1 "; 
   cout<<endl;;
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