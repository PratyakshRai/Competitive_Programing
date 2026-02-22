#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
bracket sequence diye jayenge , 

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
   string s ;cin>>s;
   if(s=="()"){
    cout<<"NO\n";
    return; 
   }
   int cnt=0;int n=s.length();
   for(int i=0;i<n;i++){
    if(s[i]=='(')cnt++;
    else cnt--;
    
   }cout<<"YES\n";
     string ans=string(n,'(');
    ans+=string(n,')');
   if(cnt!=0){
  
    cout<<ans<<"\n";
    return;
   }
   else {
    if(s==ans){
      for(int i=0;i<n;i++)cout<<"()";
      cout<<"\n";
    }else cout<<ans<<"\n";
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