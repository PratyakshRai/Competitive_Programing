#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
initially ek array di jayegi a , n>=2;
ab us array ke sare elements ko 0 karna hai ;
ek operation me l < r index choose karne , s=a^.. , then for all ai l<i<r replace it with 

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
   int n;cin>>n;
   for(int i=0;i<n;i++){
    int temp;cin>>temp;
   }
   if(n%2==0){
   cout<<"2\n";
   cout<<"1 "<<n<<"\n1 "<<n<<"\n";}
   else {
       cout<<"4\n";
   cout<<"1 "<<n-1<<"\n1 "<<n-1<<"\n";
   cout<<n-1<<" "<<n<<"\n";
   cout<<n-1<<" "<<n<<"\n";
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