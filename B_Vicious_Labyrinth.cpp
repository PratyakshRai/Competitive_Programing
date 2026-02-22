#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
k times karna hai exatly 
so 
first case : 
agar k =1 hua to : 

kuchh bhi ho jaye answer 1 hi ayega 

example 1 2 3 4 5 6 
to sab aakhiri cell me chalejayeinge except 6 wo n-1 cell me jayega 
6 6 6 6 6 5  ,ans =1; 
agar k=2 hua to 
answer : 
1st teleport :  5 th wale ko chhodke sab 5th me jayenge 5 5 5 5 6 5 aur phir sab six me except 5th one 6 6 6 6 5 6 

if k=3: 
answer : 

 

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
   int n,k;cin>>n>>k;
   if(k%2==0){
    for(int i=1;i<=n-2;i++){
      cout<<n-1<<" ";
    }
    cout<<n<<" ";
    cout<<n-1<<"\n";return;
   }else {
    for(int i=0;i<n-1;i++){
      cout<<n<<" ";
    }
    cout<<n-1<<"\n";
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