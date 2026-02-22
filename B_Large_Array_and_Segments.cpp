#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*


*/
 
// Small Observatins
/*



*/
 
 

 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*
871
810+


15*97623-(810*15+8)
*/
 //Your attacks
/*
 like pahale to ye check karenge ki  x ban paa rha hai ki nhi , 
 let s be the sum of all numbers , then s*k>=x tb jake x sum bann payega 

 phir x=x-1; karenge aur check karenge  ki kitne element ka sum x-1 ke brabar ho rha hai let say 5 elements ka sum x-1 ke brabar ho rha hai , to ham total number of elements ie n*k-5 kar denge 

 ab hame ye dekhna hai ki x-1 kitne elements ka sum hai 
 to pahale q=(x-1)/s; aur phir (x-1)=(x-1)%s; kar liya
 ab  iterate karke count++ karenge 
 final answer = n*k-(  q*n+count)

1300110

810



*/
 
void Chal_Ja_Plz(){
   int n,k,x;cin>>n>>k>>x;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   int sum=accumulate(arr.begin(),arr.end(),0LL);
   if(sum*k<x){
    cout<<"0\n";
    return;
   }
   x--;
   int q=x/sum;
   x=x%sum;
   int cnt=0,temp=0;
   for(int i=n-1;i>=0;i--){
    temp+=arr[i];
    if(temp<=x){
      cnt++;
    }
    else break;
   }
   int ans=n*k-q*n-cnt;
   cout<<ans<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}