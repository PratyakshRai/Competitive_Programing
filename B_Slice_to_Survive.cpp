#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 question pura nhi pda tha , like galat interpret kar liya tha pahalese hi , other wise kya ye ho pata mujhse ? 
 shayad han>?
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*


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
   int n,m,a,b;
   cin>>n>>m>>a>>b;
  int x1,x2,x3,x4;
  x1=ceil(log2((double)n));
  x2=ceil(log2((double)m));
  x3=ceil(log2((double )min(a,n-a+1)));
  x4=ceil(log2((double)min(b,m-b+1)));
  cout<<min(x1+x4,x2+x3)+1<<endl;

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}