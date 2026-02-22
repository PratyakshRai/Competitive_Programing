/*
Author: Pratyaksh Rai
Date: 2026-02-06
Time: 09:03:14
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
void Chal_Ja_Plz() {
    int n;
    cin >> n;

    int N = (1 << n);
    vector<int> p;
    vector<bool> used(N, false);

    for (int i = n; i >= 0; i--) {
        int mask = (1 << i) - 1;
        int step = 1 << i;

        for (int x = 0; x < N; x += step) {
            int val = x | mask;
            if (val < N && !used[val]) {
                used[val] = true;
                p.push_back(val);
            }
        }
    }

    for (int x : p) cout << x << " ";
    cout << "\n";
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