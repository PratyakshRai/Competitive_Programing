#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
operation any no of time , n  1 to n 
operations : 
choose non adjacent lamps jo ki on hai phir unko turn off kardo 


hame kuch lamp diye gayein hai jo ki turn off the , ab non adjacent lamp jo ki off hai unhe turn on karna hai 



mujhe  ye dekhna hai ki kisi bhi pattern ko kya mai bna sakta hun? 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 agar total no of lamps ans me odd hai to ans -1;


*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*
ek yes wala no milla hai iska matlab even me bhi ayesa koi case banega jisme adjacent choose karna possible nhi hai


*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;string s;cin>>s;
   
   int t=count(s.begin(),s.end(),'1');
   if(t==2){
    for(int i=0;i<n-1;i++){
      if(s[i]=='1'&&s[i+1]=='1'){
        cout<<"NO\n";
        return;
      }
    }
   }
   if(t&1)cout<<"NO\n";
   else cout<<"YES\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}