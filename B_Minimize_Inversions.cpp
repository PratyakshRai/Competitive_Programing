#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
do permutation diye hai a and b , 
ab do index diye jayeinge , i aur j aur hame ai aur aj ko swap karna hai , saath hi saath bi aur bj ko bhi swap karna hai simultaniously 

hame inversion ko minimize karwa hai dono permutation me , inversion matlab i<j but a[i]>a[j];




*/
 
// Small Observatins
/*
permutation minimize tab hoga jab bada wala peeche jaye aur choota wala aage aaye 


*/
 
 
//Your attacks
/*
 1;agar ek array ko sort kardiya to bacha dusara array ab no of inversion dusare array ke upar depend karega

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<pair<int,int>>arr(n);
   for(int i=0;i<n;i++){
    int a;cin>>a;
    arr[i].first=a;
   }
   for(int i=0;i<n;i++){
    int b;cin>>b;
    arr[i].second=b;
   }
   sort(arr.begin(),arr.end());
   for(int i=0;i<n;i++){
    cout<<arr[i].first<<" ";
   }
   cout<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i].second<<" ";
   }
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