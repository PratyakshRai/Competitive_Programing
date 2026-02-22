#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
ek binary string s me p subsequence hatana hai : p accending order me hona chahiye : 
p hatane ke baad jo bacha ie is x ley say wo palindrome hona chahiye : 
you only need to output valid subsequence p , if there is no then -1;
*/
 
// Small Observatins
/*
agar no of 1s aur 0s even hai to dono me se koi ek hata dunga sare ke sare 
agar no of 1s odd aur 0s even to 0 hata dunga sare ke sare ,and same vice versa 

ab problem tab hai jab dono odd ho bc to bhi to dono me se koi ek hata do to kaam ban jayega ; lol 


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
   string s;
   cin>>s;
   int one=count(s.begin(),s.end(),'1');
   int zero=n-one ;
   
   if(one==0||zero==0){
    cout<<"0\n";return;
   }
    cout<<zero<<'\n';
    for(int i=0;i<n;i++){
      if(s[i]=='0')cout<<i+1<<" ";
    }
    cout<<"\n";return ;
   

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}