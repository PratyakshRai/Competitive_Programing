#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek sequence diya gya hai , n integer ka 
output the maxvalue of 

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
   vector<int>a(n);
   vector<int>cnt(30,0);
   for(int i=0;i<n;i++){
  cin>>a[i];
  for(int b=0;b<30;b++){
    if(a[i]&(1LL<<b))cnt[b]++;
  }
   }
   int ans=0;
   for(int k=0;k<n;k++){
    int tot=0;
    for(int b=0;b<30;b++){
      bool bit=(a[k]>>b)&1;
      if(bit)tot+=(n-cnt[b])*(1LL<<b);
      else tot+=cnt[b]*(1LL<<b);
    }
    ans=max(ans,tot);
   }
   cout<<ans<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}