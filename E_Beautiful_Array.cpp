#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
two favorite number a and b , and an array is beautiful if its mean is exaclty divisible by a , and its median is exactly divisible by b;




 matlab hame ek array construct karna hai jiska mean a ho aur median b ho , aur hame aur kuch nhi diya gya hai , like na length 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 if a==b , then just print the element of length one 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int a,b;cin>>a>>b;
   if(a==b){
    cout<<1<<"\n";
    cout<<a<<"\n";
    return;
   }
   if(a<b){
   int x=3*a-(2*b+1);
   cout<<3<<"\n";
   cout<<x<<" "<<b<<" "<<b+1<<" \n";return;
  }
  else {
    int x=3*a-(2*b-1);
    cout<<3<<"\n";
    cout<<x<<" "<<b<<" "<<b-1<<" \n";return;
  }

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; t=1;
    while (t--) Chal_Ja_Plz();
    return 0;
}