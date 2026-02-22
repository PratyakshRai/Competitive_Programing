#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
hame ek chess ka problem diya gya hai  , jime knight , king aur queen ko kitni jagah ke fork kar sakta hai ye btana hai 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 either the solution will be 0,1,2;
 ek set bnaunga aur usme possible points king aur queeen ke saare combination daal dunga , to agar set ka size 16 hua to 0 15 to 1 14 to 2 soltion hue

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*
( -2 -1 )( -2 1 )( -1 -2 )( -1 2 )( 1 -2 )( 1 2 )( 1 4 )( 2 -1 )( 2 1 )( 2 5 )( 4 1 )( 4 5 )( 5 2 )( 5 4 )
( 0 2 )( 0 4 )( 2 0 )( 2 2 )( 2 4 )( 4 0 )( 4 2 )
( -4 -4 )( -4 4 )( 4 -4 )( 4 4 )( 12 -4 )( 12 4 )
( -3 2 )( -3 6 )( -1 0 )( -1 2 )( -1 6 )( -1 8 )( 1 0 )( 1 8 )( 3 0 )( 3 8 )( 5 0 )( 5 2 )( 5 6 )( 5 8 )( 7 2 )( 7 6 )


*/
 
 
void Chal_Ja_Plz(){
   int a,b;cin>>a>>b;
   int xk,yk;cin>>xk>>yk;
   int xq,yq;cin>>xq>>yq;
   set<pair<int,int>>st;
   
      st.insert({xk+a,yk+b});
      st.insert({xk+a,yk-b});
      st.insert({xk-a,yk+b});
      st.insert({xk-a,yk-b});
      

      st.insert({xk+b,yk+a});
      st.insert({xk+b,yk-a});
      st.insert({xk-b,yk+a});
      st.insert({xk-b,yk-a});

      
      st.insert({xq+a,yq+b});
      st.insert({xq+a,yq-b});
          st.insert({xq-a,yq+b});
      st.insert({xq-a,yq-b});
         
      st.insert({xq+b,yq+a});
      st.insert({xq+b,yq-a});
       st.insert({xq-b,yq+a});
      st.insert({xq-b,yq-a});
      if(a==b){
           cout<<8-st.size();
             cout<<endl;return ;
}
      
   cout<<16-st.size();
    cout<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}