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
set me daalo ,, ab iterate karo , 
aaga aanewala element chhota hai , set ke element se to to insert kardo , other wise subtract karke ans=max(wala)funda kardo 

 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if((arr[j]%arr[i])%2==0){
        cout<<arr[i]<<" "<<arr[j]<<"\n";
        return;
      }
    }
   }
   cout<<"-1\n";return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}