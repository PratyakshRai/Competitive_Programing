#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
do array hai , aur kuch number hai , like 1 se 2*n tak , ab ye number me se kuch array A  me  hai  , aur kuch array B me hai 

ab kuch operation karne ke baad final result me ye hoye ki 
array A aur B accending order me ho , 
array ai<bi ho 


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 to dono ko sort kardiya : 
 agar a1>b1 se to swap  



*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 #include<bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (a[j - 1] > a[j]) {
                    swap(a[j - 1], a[j]);
                    ans.push_back({1, j});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (b[j - 1] > b[j]) {
                    swap(b[j - 1], b[j]);
                    ans.push_back({2, j});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                ans.push_back({3, i + 1});
            }
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) cout << x << " " << y << '\n';
    }
    return 0;
}

