#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array di gayi hai
aur hame ek x ki value btani hai such that gcd(ai,x)=1;
aur x ki smallest value honi chahiye
like kisi bhi ek element ke saath gcd 1 ho
if not possible then print -1;

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 a aur  x  co-prime hoye 
 a ki sabse chhoti value chahiye 


 agar prime no ki series save karli to ...
 array ko sort karliya 
 do pointer laga diya 
 agar arr[i]<=b[j], i++;
 else j++ and if(gcd(arr[i],b[j])==1)exit 
 sab same no array me hai to ek set bnalunga 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
   int prime[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    };
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   for(int i=0;i<25;i++){
    for(int j:arr){
      if(gcd(prime[i],j)==1){
        cout<<prime[i]<<"\n";return;
      }
    }
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