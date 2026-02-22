/*
Author: Pratyaksh Rai
Date: 2026-02-10
Time: 12:11:26
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
 vi arr(1e6+5,0),ps(1e6+5,0);
int floor_log3(long long x) {
    int cnt = 0;
    while (x >0) {
        x /= 3;
        cnt++;
    }
    return cnt;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int l,r;cin>>l>>r;
   cout<<ps[r]-ps[l-1]+arr[l]<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=1e6;i++){
      arr[i]=(floor_log3(i));
      ps[i]=ps[i-1]+arr[i];
    }
    
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