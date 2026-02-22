#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek string di gayi hai ,jisme sirf A aur B hi hai , usme se consecutive substring hatani hai taki bachi hui string me no of A and B equal ho 

agar sare elements hatane pade to -1 print 
more over  minimum no of string to remove btana hai 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 no of A aur B count karliya, 
 ab yato A bda hoga yato  B
 agar maanlo A bda hai : 
 to no of elements to remove is A-B
 which should be the length of  consecutive elements of A atleast otherwise -1;
 
 par agar maanlo 4 element delect karna hai  B ka , aur consecutive nhi milla to hame ye dekhna hai: 
 BBABBB to is case me ek aur A ko delect karke 4 elements to be deleted bolke ham string ko equal kar kakte hai

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
   int cur=count(s.begin(),s.end(),'a')-count(s.begin(),s.end(),'b');
   map<int,int>lst;
   int pr=0;
   lst[pr]=-1;
   int ans=n;
   for(int i=0;i<n;i++){
    pr+=s[i]=='a'?1:-1;
    lst[pr]=i;
    if(lst.count(pr-cur))ans=min(ans,i-lst[pr-cur]);
   }
   cout<<(ans==n?-1: ans)<<"\n";


}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}