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
   int n,m;cin>>n>>m;
   vector<vector<char>>arr(n,vector<char>(m));
   for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<m;j++){
      arr[i][j]=s[j];
    }
   }
    vector<vector<char>>crr(n,vector<char>(m));
    vector<vector<char>>brr(n,vector<char>(m));
    crr=arr;
    brr=arr;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]=='0')break;
      if(arr[i][j]=='1')crr[i][j]='0';
    }}
    for(int j=0;j<m;j++){
      for(int i=0;i<n;i++){
        if(arr[i][j]=='0')break;
        if(arr[i][j]=='1')brr[i][j]='0';
      }
    }
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j] == '1'){
            if(crr[i][j] != '0' && brr[i][j] != '0'){
                cout<<"NO\n";
                return;
            }
        }
    }
}
cout<<"YES\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}