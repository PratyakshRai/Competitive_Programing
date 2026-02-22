#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
  how to reduce the no of palindrome 
  
  how to find the number of palindrome 

*/
 
// Small Observatins
/*

  only use a, e , i o,u
  to ham kya karte hai , ki 


  no of palindrome ke cases kaise hone 

  1> a a a a  contigiouse ho 
  2. ya phir a aur uske beech me ek kush letters ho 



  solutoin , 
  to ham kya kar sakte hai ki kyuki no of vowel 5 hai , to ham 
  ye dekhenge ki 5 ka kitna lag rha hai n ko fill karne ke liye jo ki hoga 
  
  n/5 + n%5;
  ab hame ye pta hai ki n/5 time sabhi vowel honge , ab n%5 ko add karna hai 

  simple tarike se add kardenge 


  ab smaller subsequence kaise aayega ; aato ham a ... a ke beech me kuch rakhe hi nhi , like contigious aaaa print karde 

  solved <)

 

*/
 
 
 
/*
 
*/
 
 
// Claims on algo 
/*  
    
 
*/
 
 
void solve(){
   int n;cin>>n;
   char vowel[5]={'a','e','i','o','u'};
   vector<int>arr(5,n/5);
   for(int i=0;i<n%5;i++){
    arr[i]++;
   }
   for(int i=0;i<5;i++){
    for(int j=0;j<arr[i];j++){
      cout<<vowel[i];
    }
   }
   cout<<"\n";
   return ;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}