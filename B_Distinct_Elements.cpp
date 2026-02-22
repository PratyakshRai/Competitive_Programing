#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
ek array di gayi hai array c , f(c)hame btata hai no of distinct elements of that array 

ek array hai A size n ki aur dusari array b hai n elements ki 
condition 
bi=f(a[1,i])+f(a[2,i])+f(a[3,i])....+f(a[i,i]);
ab b diya hai aur hame a bnana hai 

*/
 
// Small Observatins
/*
example se samajhne ki koshish rhe gi 


a atleat 
[1,2,3,4,5,6]
to b kaise bnega:
[1,3,6,10...] ye hai maximum range 
agar a ye rha [1,1,1,1,1,1]
to b : [1,2,3,4,5,6]
[1,2,3,7,13,] 
[1,1,1,2,3,3]
[1,2,3,4,5,6]


0 1 2 3 4 5 6 



min : [1,2,3,4,5,6]
max : [1,3,6,10...]

a ke har element ke liye ek range hai , agar b[i+1]-b[i]ka difference 1 se le ke max-1 tak hai to koi nya element add nhi karna hai balki us index pe jake same element ko lga dena hai
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
 int n ;
 cin>>n;
 vector<int>arr(n + 1);
 arr[0]=1;
 vector<int>b(n);
 for(int &i: b)cin>>i;
 int cnt =1;
 for(int i=1;i<n;i++){
  int diff=b[i]-b[i-1];
  if(i-diff>=0)arr[i]=arr[i-diff];
  else arr[i]=++cnt;

 }
 for(int i=0;i<n;i++)cout<<arr[i]<<" ";
 cout<<"\n";


}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}