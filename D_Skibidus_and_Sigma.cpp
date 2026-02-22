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
 void Chal_Ja_Plz(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<pair<long long,int>> a(n);
    for(int i = 0; i < n; i++){
        long long sum = accumulate(arr[i].begin(), arr[i].end(), 0LL);
        a[i] = {sum, i};  // (sum, original index)
    }

    // ❌ WRONG
    // sort(arr.begin(), arr.end());

    // ✔️ CORRECT
    sort(a.begin(), a.end(),greater<pair<int,int>>());   // sort rows by sum

    long long ans = 0;
    long long pre = 0;

    for(int i = 0; i < n; i++){
        int idx = a[i].second; // correct row index after sorting

        for(int j = 0; j < m; j++){
            arr[idx][j] = pre + arr[idx][j];
            pre = arr[idx][j];
        }
    }

    for(int i = 0; i < n; i++){
        int idx = a[i].second;
        for(int j = 0; j < m; j++){
         ans+=arr[idx][j];
        }
     
    }
    cout<<ans<<"\n";

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}