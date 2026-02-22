/*
Author: Pratyaksh Rai
Date: 2026-01-12
Time: 23:29:16
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
  int n;cin>>n;
  vi arr(n);
  invec(arr);
   vector<int>prefix(n+1);
   for(int i=0;i<n;i++){
    prefix[i+1]=prefix[i]+arr[i];
   }
   vector<int>divisor;
   for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
        divisor.push_back(i);
        if(i != n / i)
            divisor.push_back(n / i);
    }
}
divisor.pb(n);
   int ans=*max_element(all(arr))-*min_element(all(arr));
 
   for(int i=0;i<divisor.size();i++){
    int div=divisor[i];
    set<int>st;
    int prev=prefix[0];
    int curr=div;
    while(curr<=n){
      int sum=prefix[curr]-prev;
      prev=prefix[curr];
      curr+=div;
      st.insert(sum);
    }
    if(!st.empty()){
    int mn = *st.begin();
    int mx = *st.rbegin();
    ans=max(ans, mx-mn);
}
   }
   cout<<ans<<endl;
  
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