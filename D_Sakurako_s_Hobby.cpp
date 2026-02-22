#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

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
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n+1);
  for(int i=1;i<=n;i++)cin>>arr[i];
   string s ;cin>>s;
   s="#"+s;
   vector<int>visited(n+1,0);
   
   unordered_map<int,int>mp;
   for(int i=1;i<=n;i++){
    vector<int>b;
    int cnt=0;
    int idx=i;
    bool found=false;
    while(visited[idx]==0){
      visited[idx]=1;
      if(s[idx]=='0')cnt++;
      b.push_back(arr[idx]);
      idx=arr[idx];
      found =true;

    }
    if(found){
      for(int t:b){
        mp.insert({t,cnt});
      }
    }
   }
   for(int i=1;i<=n;i++){
    cout<<mp[arr[i]]<<" ";
   }
   cout<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}