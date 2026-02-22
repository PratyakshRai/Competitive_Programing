#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
n points with increasing 

you have to draw line segment 



now you are given n queries , in the ith querry , you are given a positive integer k , and you have to determine how many points with integer coordinates are contained in exactly ki segments

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

to matlab total number of line segments nikalenge , using combination simple , phir usko map me save kar lenge  ,  aur phir wo sare points ke segments ko bhi add karenge so vector me nhi diya hai ,like the gaps between the points uske liye alag tarike se karenge , at the end q querries ka reply to easy hi hoga 

*/
 
 
void Chal_Ja_Plz(){
   int n,q;cin>>n>>q;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   map<int,int>mp;
   for(int i=0;i<n;i++){
    int temp=(i+1)*(n-i)-1;
    mp[temp]++;
    if(i>0){
      int temp1=(n-i)*i;
      mp[temp1]+=(arr[i]-arr[i-1]-1);
    }
   }
  while(q--){
    int k ;cin>>k;
    if(mp.find(k)==mp.end()){
      cout<<"0 ";
      
    }
    else cout<<mp[k]<<" ";
  }
  cout<<'\n';
  return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}