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
   string s;cin>>s;
   vector<char>arr;
   for(int i=0;i<10;i++){
    arr.push_back(s[i]);
   }
   int b[10]={0};
   for(int i=0;i<10;i++){
    b[s[i]-'0']++;
   }
   int idx=9;
   for(int i=0;i<5;i++){
    while(idx>=0&&idx<10&&b[idx]==0)idx--;
    cout<<b[idx];b[idx]--;
   }
   for(int i=0;i<5;i++){
    while(idx>=0&&idx<10&&b[idx]==0)idx
   }

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}