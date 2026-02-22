/*
Author: Pratyaksh Rai
Date: 2026-02-18
Time: 11:35:06
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
   vi arr(n);vector<bool>exit(k+1,false);
   vi first(k+1,n+1),last(k+1,-1);
   for(int i=0;i<n;i++){
    cin>>arr[i];
    exit[arr[i]]=true;
    first[arr[i]]= min(i,first[arr[i]]);
    last[arr[i]]=max(i,last[arr[i]]);
   }
   vi result(k+1);
   int currf=n-1,currl=-1;
   for(int i=k;i>=1;i--){
    currf=min(first[i],currf);
    currl=max(last[i],currl);
    if(exit[i]){
      result[i]=2LL*(currl-currf+1);
    }
   }
   for(int i=1;i<=k;i++){
    cout<<result[i]<<(i==k?" ":" ");
   }
   cout<<endl;
  //  vector<pair<int,int>>arr(n);
  //  for(int i=0;i<n;i++){
  //   int x;cin>>x;
  //   arr[i]={x,i};
  //  }
  //  sort(all(arr));
  //  map<int,set<int>>mp;
  //  for(int i=n-1;i>=0;i--){
  //  if(i==n-1) mp[arr[i].ff].insert(arr[i].ss);
  //  else {mp[arr[i].ff]=mp[arr[i+1].ff];mp[arr[i].ff].insert(arr[i].ss);}

  //  }
  //  for(int i=1;i<=k;i++){
  //   if(mp.find(i)==mp.end()){
  //     cout<<"0 ";
  //   }
  //   else {
  //     auto it =mp[i];
  //     // cout<<"( "<<(*it.begin())<<" "<<(*it.rbegin())<<" )";
  //     int dis=(*it.rbegin())-(*it.begin());
  //     cout<<(dis+1)*2<<" ";
  //   }
  //  }
  //  cout<<endl;;
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