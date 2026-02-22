/*
Author: Pratyaksh Rai
Date: 2026-01-17
Time: 20:17:19
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
let do mex hai , 1 to i aur ++i to n , is M 
do 1 to n bhi M hoga , phir har point me check karenge , aur jaha bhi M ke bra bar nhi hua , waha no , 

    dono taraf se iterate kardene , like reverse and normal , kyuki ....
*/
// Hints From Code 
/*  

*/
int suffix_mex(const vector<int>& a, int i){
    int n = a.size();
    vector<bool> seen(n + 1, false);

    for(int j = i; j < n; j++){
        if(a[j] <= n)
            seen[a[j]] = true;
    }

    for(int m = 0; m <= n; m++){
        if(!seen[m]) return m;
    }
    return n;
}
int normal_mex(vector<int>&arr,int idx){
  int n=arr.size();
  vector<bool>seen(idx+2,false);
  for(int i =0;i<=idx;i++){
    seen[arr[i]]=true;
  }
  for(int i=0;i<=idx;i++){
    if(!seen[i])return i;
  }
  return idx+1;

}
vector<int> prefix_mex(const vector<int>& a){
    int n = a.size();
    vector<int> freq(n + 2, 0);
    vector<int> mex(n);

    int cur = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= n)
            freq[a[i]]++;

        while(freq[cur] > 0)
            cur++;

        mex[i] = cur;
    }
    return mex;
}
vector<int> suffix_mex(const vector<int>& a){
    int n = a.size();
    vector<int> freq(n + 2, 0);
    vector<int> mex(n);

    int cur = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] <= n)
            freq[a[i]]++;

        while(freq[cur] > 0)
            cur++;

        mex[i] = cur;
    }
    return mex;
}
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
  //  vector<int>frq(n+1,0);
  //  for(int it: arr)frq[it]++;
  //  int mex=0;
  //  while(frq[mex]>0)mex++;
  //  for(int i=0;i<mex;i++)
//    int mex=normal_mex(arr,n-1);
//    for(int i=0;i<n;i++){
//     int mx1=suffix_mex(arr,i);
//     int mx2=normal_mex(arr,i);
//     if(mx1!=mex||mx2!=mex){
//       YES;return;
//     }
//    }
// NO;
// vector<int>pre(n),suff(n);
// pre=prefix_mex(arr);
// suff=suffix_mex(arr);
// for(int i=0;i<n;i++){
//   if(pre[i]!=suff[i]){
//     YES;
//     return;
//   }
// }
// NO;
int zero=count(arr.begin(),arr.end(),0);
if(zero==1){
  YES;
  return;
}else if(zero==0){
  NO;
  return;
}
int mex=normal_mex(arr, n-1);
if(mex>1){
  YES;
}else NO;

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