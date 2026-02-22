#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
nxn matrix diya hai 
aij heigh btata hai , <0 rha to lake hogi,otherwi

';lk

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
  map<int,int>mp;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int temp;cin>>temp;
      int x=i-j;
      if(mp.find(x)==mp.end()){
        mp[x]=temp;
      }
      else {
        mp[x]=min(mp[x],temp);
      }
    }
   }int ans=0;
   for(auto [k,v]:mp){
    if(v<=0)ans+=(abs(v-0));
   }
   cout<<ans<<'\n';
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}