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
  int n, k;cin>>n>>k;
  vi arr(2*n);
  invec(arr);
  map<int,int>mp1,mp2;
  for(int i=0;i<n;i++){
    int t=arr[i];
    if(mp1.find(t)==mp1.end()){
      mp1[t]=1;
    }else mp1[t]++;
  }
   for(int i=n;i<2*n;i++){
    int t=arr[i];
    if(mp2.find(t)==mp2.end()){
      mp2[t]=1;
    }else mp2[t]++;
  }
  vi d1,d2;
  for(auto it : mp1){
    if(it.ss==2){
      d1.push_back(it.ff);
    }
  }
  for(auto it: mp2){
    if(it.ss==2){
      d2.push_back(it.ff);
    }
  }
  int i=0;
  vector<int>a1,a2;
  int t=d1.size();
  while(i<t&&k>0){
    a1.pb(d1[i]);
    a1.pb(d1[i]);
    a2.pb(d2[i]);
    a2.pb(d2[i]);
    i++;
    k-=1;
  }
  int y=2*k;
  for(auto it :mp1){
  if(y==0)break;
  if(it.ss==2)continue;
  a1.pb(it.ff);
  a2.pb(it.ff);
  y--;
}
for(int i: a1)cout<<i<<" ";
cout<<endl;
for(int i: a2)cout<<i<<" ";
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