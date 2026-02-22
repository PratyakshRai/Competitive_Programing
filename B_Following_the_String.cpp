#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
hame traces diye gayein hai , jo ki ye btate hai ki usse pahale wo element kitni baar aaya hai

*/
 
// Small Observatins
/*
har i par 26 letters iterate honge

*/
 
 
//Your attacks
/*
 ham ek counter rakh lenge jisko ++ karke sare alphabests laa sake ;
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
  int n;cin>>n;
  vector<int>arr(26);
  int k=0;
  string ans="";
  for(int i=0;i<n;i++){
    int cnt;cin>>cnt;
    if(cnt==0){
      ans+='a'+k;
      arr[k]++;
      k++;

    }
    else {
      for(int j=0;j<26;j++){
        if(arr[j]==cnt){
          ans+='a'+j;
          arr[j]++;
          break;
        }
      }
    }
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