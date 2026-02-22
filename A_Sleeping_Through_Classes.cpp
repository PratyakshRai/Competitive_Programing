#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

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
 
 
// Learn form question
/*



*/
 
 void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int awake_until = -1;  // last index where you're forced to stay awake
    int sleep = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
           
            awake_until = max(awake_until, i + k);
        } else {
           
            if (i > awake_until) {
               
                sleep++;
            }
           
        }
    }

    cout << sleep << "\n";
}

 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}