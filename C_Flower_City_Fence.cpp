/*
Author: Pratyaksh Rai
Date: 2026-01-18
Time: 20:58:09
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
    symmetry check ? 
    axis transform kar lu phir check karun ki 1 , 2, 3... se >= kaun kaun hai , phir 
    match karalo , time complexity nlogn
*/
// Hints From Code 
/*  

*/
int find(vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   vi brr=arr;
   sort(all(brr));
 

   for(int i=1;i<=n;i++){
    int pos=find(brr , i);
    // cout<<"("<<pos<<" "<<arr[i-1]<<" )";
    // if(pos==-1){
    //   if(n!=arr[i]){
    //     NO;return;
    //   }
    // }
    // else if (n-pos!=arr[i]){
    //   NO;return;
    // }
   if(n-pos-1!=arr[i-1]){
    NO;
    return;
   }

   }
   YES;
  
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