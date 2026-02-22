#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
elements ko uda hi de rha hai instead of sorting , if they are not in their place 

sorting subarray pe lga sakte hai 
nonincreasing order me chahiye 

an array is vulnerable if you can sort it 

minimum no of integers which must be removed to make it velnerable 



 stalin sort increasing order me sort karega, aur hame decreasing order chahiye 


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
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   int ans=1e9;
   for(int i=0;i<n;i++){
    int del=0;
    for(int j=i+1;j<n;j++){
        if(arr[j]>arr[i])del++;
    }
    ans=min(ans,del+i);
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