#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
to five language hi use ho rhe hai sirf  , ie a ,b,c,d,e;

hamare paass vowel hai , a,e 
aur consonent hai b,c ,d 

hamare pass do syllabus hai , cv consonent followed by vowel or cvc
vowel with consonent after and before ;

ek word is language me sequence of syllabus hai , ab hame syllabus me todna hai



*/
 
// Small Observatins
/*

to do vv ke sath kabhi nhi ayega 
do cc agar aaya , tab c.c
vc  

*/
 
 
//Your attacks
/*
cvc 


*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*

ba.ced.bab


*/
 bool isvowel(char ch){
  return (ch=='a'||ch=='e');
 }
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s; cin>>s;
   string ans="";
   for(int i=0;i<n;i++){
    if(!isvowel(s[i]))ans+=s[i];
   else {
    int cnt=0;
    ans+=s[i];
    i++;
    
    int j=i;
    while(j<n&&(!isvowel(s[j]))){
      j++;cnt++;
    }
    if(cnt==2){
      ans+=s[i];
      ans+='.';
    }
    else if(cnt==1&&j<n) {
      ans+='.';i--;
    }else {
      if(i<n){
      ans+=s[i];
    }}
   }}
   cout<<ans<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}