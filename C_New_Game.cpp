/*
Author: Pratyaksh Rai
Date: 2026-02-08
Time: 14:27:48
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
  int n,k;cin>>n>>k;

    map<int,int>mp;
    for(int i=0;i<n;i++){
      int x ;cin>>x;
      mp[x]++;
    }
    vi arr;
    for(auto it : mp)arr.pb(it.first);
    // for(int i: arr)cout<<i<<" ";
    int ans=0;
    set<int>curr;
    int prev=-1;
    int idx=0,re=0;
    for(int i=0;i<arr.size();i++){
     
        if(prev==-1||prev==arr[i]-1)
        {
          curr.insert(arr[i]);
        ans+=mp[arr[i]];
      }
      else {
        curr.clear();
        curr.insert(arr[i]);
        ans=0;
        ans+=mp[arr[i]];
        idx=i;
      }
      prev=arr[i];
       if(curr.size()>k){
        while(curr.size()>k){
          curr.erase(arr[idx]);

          ans-=mp[arr[idx]];
          idx++;
        }
       }
       re=max(ans,re);
      
    }
    cout<<re<<endl;
   
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