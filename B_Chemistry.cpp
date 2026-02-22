#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
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
   int n,k;cin>>n>>k;
   string s;cin>>s;
   vector<int>arr(26,0);
   for(int i=0;i<n;i++){
    arr[s[i]-'a']++;
   }
   int cnt=0;
   for(int i=0;i<26;i++){
    if(arr[i]%2!=0)cnt++;
   }
   if(((k==n-1)||k>=cnt-1))cout<<"YES\n";
   else cout<<"NO\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}