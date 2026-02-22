/*
Author: Pratyaksh Rai
Date: 2026-02-21
Time: 11:01:02
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
  vi arr(n);
  invec(arr);
  sort(all(arr));
  map<int,bool>mp;
  for(int i:arr){
    mp[i]=false;
  } 
  vi ans;
  for(int i=0;i<n;i++){
    int number = arr[i];
    int lim=k/arr[i];
    if(mp[number]==false){
      ans.pb(number);
    for(int j=number ;j<=k;j+=number){
      if(mp.find(j)==mp.end()){
        cout<<"-1\n";return;
      }
      mp[j]=true;
    }
    
  }
  }

  cout<<ans.size()<<endl;
  for(int i: ans )cout<<i<<" ";
  cout<<endl;
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