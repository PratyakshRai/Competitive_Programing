#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
for an array b we define a function f(b) as the smallest number of the following operations required to make the array b empty : 

take two 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 to normal case me dekho ki kitne operations lagte hai i.e size of the set 
 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n,k;cin>>n>>k;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   map<int,int>mp;
   for(int i=0;i<n;i++){
    mp[arr[i]]++;
   }
  vector<pair<int,int>>f;
  for(auto it : mp){
    f.push_back({it.second,it.first});

  }
  sort(f.begin(),f.end());
  int i=0;
  while(k--&&i<n){
    f[i].first--;
    if(f[i].first==0)i++;
  }
  set<int>st;
  for(auto it:f){
    if(it.first>0)st.insert(it.second);
  }
  if(st.size()==0){
    cout<<"1\n";return;
  }
  cout<<st.size()<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}