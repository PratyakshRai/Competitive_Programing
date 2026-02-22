#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
prefix sum se kiya ja sakta hai 


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
  
   map<int,int>lastprefix;
   lastprefix[0]=0;
   int prefix=0;
   vector<pair<int,int>>segments;
for(int i=0;i<n;i++){
    int x ;cin>>x;
    prefix+=x;
    if(lastprefix.find(prefix)!=lastprefix.end()){
        int lastind=lastprefix[prefix];
        segments.push_back({i,lastind+1});
    }
    lastprefix[prefix]=i;
}
sort(segments.begin(),segments.end());
int answer=0;
int lastend=-1;
for(auto it : segments){
    if(it.second>lastend){
        answer++;
        lastend=it.first;
    }
}
cout<<answer<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}