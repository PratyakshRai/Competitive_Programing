/*
Author: Pratyaksh Rai
Date: 2026-04-02
Time: 23:33:41
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
#define setbits(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define invec(v) for(int &i : v) cin >> i;
// Common constants
const int INF = 1e18; 
const int MOD = 1e9 + 7;

// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
#define ll long long
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
There is always a simpler solution for the question 
*/
   int n; cin >> n;
		vector<vector<int>> a(2, vector<int>(n));
		for(auto &aa : a) for(auto &x : aa) cin >> x;
 
		vector<int> suf_mx = a[1], suf_mn = a[1];
		for(int j = n-2; j >= 0; j--) {
			suf_mn[j] = min(suf_mn[j], suf_mn[j+1]);
			suf_mx[j] = max(suf_mx[j], suf_mx[j+1]);
		}
 
		vector<int> anss(2*n, 2*n);
		int pref_mn = a[0][0], pref_mx = a[0][0];
		for(int j = 0; j < n; j++) {
			pref_mn = min(pref_mn, a[0][j]);
			pref_mx = max(pref_mx, a[0][j]);
			int mn = min(pref_mn, suf_mn[j]);
			int mx = max(pref_mx, suf_mx[j]);
			// [l, r] = [mn, mx]
			anss[mn-1] = min(anss[mn-1], mx-1);
		}
 
		for(int i = 2*n - 2; i >= 0; i--) {
			anss[i] = min(anss[i], anss[i+1]);
		}
 
		ll ans = 0;
		for(auto x : anss) ans += (2*n - x);
 
		cout << ans << "\n";
	
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