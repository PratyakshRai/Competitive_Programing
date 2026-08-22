/*
Author: Pratyaksh Rai
Date: 2026-02-25
Time: 19:03:19
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
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
  int n;cin>>n;
  vi arr(n);
  invec(arr);
  int cnt=0,prev=-1;
  for(int i=0;i<n;i++){
    if(prev==-1){
      prev=arr[i];
      cnt++;
    }
    else if(prev==arr[i])cnt++;
    else if(prev!=arr[i])break;
  } 
  // cout<<cnt<<endl;
  if(cnt==n){
    cout<<"0\n";return;
  }
  int back=0;
  prev=-1;
  for(int i=n-1;i>=0;i--){
    if(prev==-1){
      back++;
      prev=arr[i];
    }else if (prev==arr[i])back++;
    else if(prev!=arr[i])break;
  }
  if(arr[0]==arr[n-1]){cnt+=back;cout<<n-cnt<<endl;}
  else cout<<n-max(cnt,back)<<endl;
  
 
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