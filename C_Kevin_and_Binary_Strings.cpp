#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
a binary string s starts with  1 

select two nonempty substrings of s which can be overlap , to maximize the xor value of these two substring 

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
  string s; cin>>s;
  int n =s.size();
  s="#"+s;
  int first=-1;
  for(int i =1;i<s.size();i++){
    if(s[i]=='0'){
      first=i;
      break;
    }
  }
  if(first==-1){
    cout<<1<<" "<<s.size()-1<<" 1 1"<<"\n";
    return; 
  }
  int cnt =0;
  for(int i=first;i<s.size();i++ ){
    if(s[i]=='0')cnt++;
    else break;
  }
  int select =min(first-1, cnt);
  //first -select se le ke n -1 -select 
  cout<<first-select<<" "<<n-select<<" 1"<<" "<<n<<"\n";return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}