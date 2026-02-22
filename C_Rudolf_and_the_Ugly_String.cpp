#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
do word diye gaye hai map aur pie
minimum word nikal do ki map aur pie ye dono hi ek given string me appear na ho 

*/
 
// Small Observatins
/*
ayese to simple iterate karenge aur jaha map aur pie aa rha hai wha counter ko ++ kardenge ,but jha cheese common hai 
jaise mapie yaha par  counter ek baar hi plus hoga;


*/
 
 
//Your attacks
/*
 to agar map configuration ban rhi hai to use p ka index ka frequency save karlenge , similary pie me bhi 
 ab agar p ke index ki frequency 1 hai to theek agar 2 hai to cnt me -- karenge  
 lol
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s;cin>>s;
   int cnt=0;
   vector<int>arr(n+5);
   for(int i=0;i<n-2;i++){
    string res="";
    res+=s[i];
    res+=s[i+1];
    res+=s[i+2];
    if(res=="map"){
      cnt++;
      arr[i+2]++;
    }
    if(res=="pie"){
      cnt++;
      arr[i]++;
    }
   }
   for(int i: arr){
    if(i==2)cnt--;
   }
   cout<<cnt<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}