#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array di gai hai , n length ki with non zero int 
you have 0 coins and you will do the following until a is empty: 
let m be the current size of array, 
select an integer ai and you will gain mod of ai coins and then if the elements that you selected is negative then delect the suffix and if the element is positive delect the prefix 

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
   for(int &i:a)cin>>i;
   vector<int>pre(n),suf(n);
   if(a[0]>0)pre[0]=a[0];
   for(int i=1;i<n;i++){
    pre[i]=pre[i-1];
    if(a[i]>0)pre[i]+=a[i];
   }
   if(a[n-1]<0){
    suf[n-1]=-a[n-1];
   }
   for(int i=n-2;i>=0;i--){
    suf[i]=suf[i+1];
    if(a[i]<0)suf[i]-=a[i];
   }
   int ans =0;
   for(int i=0;i<n;i++){
    ans=max(ans,pre[i]+suf[i]);
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