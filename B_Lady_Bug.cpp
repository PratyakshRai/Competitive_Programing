#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek password diya gya hai , consists of two bit string a and b 
each of which has a lenght n, 
in one operation ,you can choose any index and do some swap 
make first string zero 

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
   string a,b;cin>>a>>b;
   int cnt=count(a.begin(),a.end(),'0');
   if(cnt==n){
    cout<<"YES\n";return;
   }
   int fz=0,fo=0;
   int sz=0,so=0;
   for(int i=0;i<n;i+=2){
    if(a[i]=='0')fz++;
    else fo++;
    if(i<n-1&&b[i+1]=='0')fz++;
    else if(i<n-1&&b[i+1]=='1')fo++;
   }
   for(int i=0;i<n;i+=2){
    if(b[i]=='0')sz++;
    else so++;
    if(i<n-1&&a[i+1]=='0')sz++;
    else if(i<n-1&&a[i+1]=='1')so++;
   }
   int x=(n+1)/2;
   int y=n/2;
   if(fz>=x&&sz>=y)cout<<"YES\n";
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