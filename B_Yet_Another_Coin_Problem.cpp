/*
Author: Pratyaksh Rai
Date: 2026-01-20
Time: 22:50:23
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
      mai koshish karunga ki sabse bda no pahale choose kru
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   int ans=0;
   int f=n/15;
   ans+=n/15;
   n=n%15;
   int ten=n/10;
   ans+=n/10;
   n=n%10;
   int six=n/6;
   ans+=n/6;
   n=n%6;
   ans+=n/3;
   int t=n/3;
   n=n%3;
   ans+=n;
   if(f>=1&&t>=1&&n>1)ans-=2;
   if(ten>=1&&n>1)ans-=1;
   if(f>=1&&six>=1&&n==2)ans--;
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