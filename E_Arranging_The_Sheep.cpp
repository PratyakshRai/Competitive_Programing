/*
Author: Pratyaksh Rai
Date: 2026-03-26
Time: 18:57:24
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

        arrange the sheep in the line up 


        * represents sheep 
        . represents empty space 

        minimum no of moves to complete the level ? 





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
string s; cin>>s;
vi idx;
for(int i=0;i<n;i++)if(s[i]=='*')idx.pb(i);
if(idx.size()==0){
  cout<<"0\n";return;
}
int ans=0;
for(int i=0;i<idx.size();i++){
  ans+=abs(idx[idx.size()/2]-idx[i]);

}
int l=idx.size()/2;
int r=idx.size()/2;
if(idx.size()%2==0)r--;
cout<<ans-((l*(l+1))/2+(r*(r+1))/2)<<endl;
   
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