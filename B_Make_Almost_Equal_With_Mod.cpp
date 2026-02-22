/*
Author: Pratyaksh Rai
Date: 2026-01-22
Time: 09:47:34
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
array should contain exactly two distinct values

    can we do k=2;, like either the number is even or the number is odd

     wrong idea , binay me right to left travel and 1 aneke baad pahaka zero at is at fith position   , then  2^that position will be your answer 
     kyuki wo sabse smallest hai , aur sare 000s wale uske baad ayen ge that is why it can divide all the numbers greater than the zero postion 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
    int n; cin >> n;
    vector<long long> arr(n);
    for(auto &x : arr) cin >> x;
    int ans = -1;
    for(int i = 0; i <= 61; i++){
        long long t = (1LL << i);
        bool diff = false;
        for(int j = 1; j < n; j++){
            if ((arr[j-1] & t) != (arr[j] & t)) {
                diff = true;
                break;
            }
        }
        if (diff) {
            ans = i;
            break; 
        }
    }
    ans++;

    cout << (1LL << ans) << endl;
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