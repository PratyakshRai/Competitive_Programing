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
 minimum* length jaise hi x ke equal ya bda hoga count++ kardenge 

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
    int n,x;cin>>n>>x;
    vector<int>arr(n);
    for(int &i:arr)cin>>i;
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    int p=0,mn=1e18,cnt=0;
    for(int i=0;i<n;i++){
      mn=min(mn,arr[i]);
      if((i+1-p)*mn>=x){
        cnt++;
        p=i+1;
        mn=1e18;
      }
    }
    cout<<cnt<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}