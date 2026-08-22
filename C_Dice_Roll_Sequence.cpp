/*
Author: Pratyaksh Rai
Date: 2026-03-24
Time: 22:01:17
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

      ek dice sequence bnana hai ya correct karna hai minimum no of operation use karke 

       such that all the adjacent elements in the array lie on the adjacent sides of the cube 

       the back side of the cube is give as  
        
           if x is the front side , then the back side is 7-x 

           so except the back side any side can be putted there

           more over you have to put it in such a way that 
           in future or the upcomming side will not conflict 



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
    int n; cin >> n;
    vi a(n);
    invec(a);

    int ans = 0;

    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1] || a[i] + a[i-1] == 7){
            ans++;
            a[i]=-1;
        }
    }

    cout << ans << endl;
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