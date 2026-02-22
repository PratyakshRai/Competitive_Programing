#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
n message bhejne hai , m1 ,m2,m3 ...sec par 
mi<mi+1 obiously 

moment 0 par f unit charge hai phone 
ab a units of charge har second discharge ho rha hai 
aur ham chaheto phone ko switch off kar sakte hai  ,usme b unit of charge lagega

*/
 
// Small Observatins
/*
to hame units of charge ko save karna hai , to maan lo 0 se m1 tak gya to hamare pass do options hai 
yato 0 se m1 tak phone on rakhu ya to 0 par hi phone off karlu  aur phir m1 par phone on karke message bhejdu

indono me jo minimum hoga use har message ke liye add karenge phir dekhenge ki total charge kitna lag rha hai 
phir boom ans 


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
   int n,f,a,b;cin>>n>>f>>a>>b;
   vector<int>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int total=0;
   int prev=0;
   for(int i=0;i<n;i++){
    int time=arr[i]-prev;
    prev=arr[i];
    
    total+=min(time*a,b);
   }

   if(total>=f){
    cout<<"NO\n";
   }else cout<<"YES\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}