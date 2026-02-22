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
   vector<int>arr(n),freq(n+1);
   for(int i =0;i<n;i++){
    int temp;cin>>temp;
    arr[i]=temp;
    freq[temp]++;
   }
  
   queue<int>q;
   for(int i=1;i<=n;i++){
    if(freq[i]==0)q.push(i);
   }
   vector<int>v(n+1);
   for(int i=0;i<n;i++){
    if(v[arr[i]]==0){
      cout<<arr[i]<<" ";
      v[arr[i]]++;
    }
    else {
      int t=q.front();
      cout<<t<<" ";
      q.pop();
    }
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