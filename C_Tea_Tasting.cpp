/*
Author: Pratyaksh Rai
Date: 2026-03-29
Time: 21:20:12
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
There is always a simpler solution for the question 
*/
  int n;cin>>n;
  vi a(n),b(n);
  invec(a);
  invec(b);
  vi pref(n);
  pref[0]=b[0];
  for(int i=1;i<n;i++)pref[i]=pref[i-1]+b[i];
  vi rem(n+2);
  vi result (n+2);
  int sum =0;
  for(int i = 0 ;i<n;i++){
    int  idx =upper_bound(pref.begin()+i,pref.end(),a[i]+sum)-pref.begin();
    
 
    if(idx==i){
      rem[idx]+=min(a[i],b[i]);sum+=b[i];
      continue;
    }
    idx--;
    result[i]++;
    result[idx+1]--;
    if(pref[idx]-sum<a[i]){
      rem[idx+1]+=a[i]-pref[idx]+sum ;

    }
    sum+=b[i];

  } 
  for(int i=1;i<n;i++)result[i]+=result[i-1];
  for(int i=0 ;i<n;i++)cout<<(rem[i]+b[i]*result[i])<<" ";
  cout<<endl;;
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