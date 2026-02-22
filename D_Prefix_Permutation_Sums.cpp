/*
Author: Pratyaksh Rai
Date: 2026-02-18
Time: 22:37:46
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
solution by gpt
*/
void solve(){
    int n;
    cin >> n;

    vector<long long> a(n-1);
    for(auto &x : a) cin >> x;

    vector<long long> diff;
    diff.push_back(a[0]);

    for(int i = 1; i < n-1; i++){
        diff.push_back(a[i] - a[i-1]);
    }

    vector<int> used(n+1,0);
    long long extra = -1;

    for(auto d : diff){
        if(d >= 1 && d <= n && !used[d]){
            used[d] = 1;
        }
        else{
            extra = d;
        }
    }

    vector<int> missing;
    for(int i = 1; i <= n; i++){
        if(!used[i]) missing.push_back(i);
    }

    if(missing.size() == 1){
        cout << "YES\n";
    }
    else if(missing.size() == 2){
        if(missing[0] + missing[1] == extra)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else{
        cout << "NO\n";
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/