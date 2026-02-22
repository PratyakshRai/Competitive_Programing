#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek binary string di gayi 
after performing q operations she wants to make it more beautiful
   
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
int n;
string s;
 bool check1100(int i){
  if(i<0||i+3>=n)return false;
  return s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0';
 }
 
void Chal_Ja_Plz(){

cin>>s;
 n=s.size();
  int q;cin>>q;
int cnt=0;
for(int i=0;i<n;i++){
  if(check1100(i))cnt++;
}
while(q--){
  int idx , val;
  cin>>idx>>val;
  idx--;
  if(s[idx]!=char('0'+val)){
    bool before= check1100(idx - 3) ||
                check1100(idx - 2) ||
                check1100(idx - 1) ||
                check1100(idx);

            s[idx] = char('0' + val);

      
            bool after =
                check1100(idx - 3) ||
                check1100(idx - 2) ||
                check1100(idx - 1) ||
                check1100(idx);

           
       cnt += (after - before);
  }
  cout<<(cnt>0?"YES\n":"NO\n");
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