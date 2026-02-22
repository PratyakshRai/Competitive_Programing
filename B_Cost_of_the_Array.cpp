#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array di gayi hai a length n 
and an even integer k , you need to split the array a into exactly k non empty subarray , such 

all subarrays with even indices are concatendatedinto single array b after that 0 is added to the end of the array b , 
the cost of b is defined as teh minimum index i such that bi!=i , for example 
determine the minimum cost of the array that can be obtained by optimal partioning 


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
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   if(k==n){
    int  c=1;
    for(int i=1;i<n;i+=2){
        if(arr[i]!=c){
            cout<<c<<"\n";
            return;
        }else c++;
    }
    cout<<c<<"\n";return;
   }
   for(int i=1;i<=n-k+1;i++){
    if(arr[i]!=1){
        cout<<"1\n";return;
    }
   }
   cout<<"2\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}