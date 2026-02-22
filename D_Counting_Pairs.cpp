#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
to ek sequence diya gya hai consisting of  n intger 
you are given x and y x<=y; 

a pair of integer is consider interesting if the following conditions are met : 
i<j<=n
if you simultaneously remove the element at postition i and j the sum of the  remaining elements is at least x and at most y 
your task is to determine the no of such pair 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 1: 
 sort the array 
  2: 
  take two pointer sum - i - j should be within the range (x,y);
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 int calculateL (vector<int>&arr , int x,int l, int n){
    int low =l ;int high=n-1;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(arr[mid]>=x)high=mid-1;
        else low =mid+1;
    }
    return low ;
 }
  int calculateR (vector<int>&arr , int x,int l, int n){
    int low =l ;int high=n-1;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(arr[mid]>x)high=mid-1;
        else low =mid+1;
    }
    return high ;
 }
void Chal_Ja_Plz(){
   int n,x,y;
   cin>>n >>x>>y;
   vector<int>arr(n);
 
   for(int &i : arr)cin>>i;
     int sum =accumulate(arr.begin(),arr.end(),0LL);
   sort(arr.begin(),arr.end());
   int ans =0;
   for(int i=0;i<n;i++){
    int req=sum-arr[i];
    int Y=req-x;
    int X=req-y;
    int l=calculateL(arr,X,i+1,n);
    int r =calculateR(arr,Y,i+1,n);
    
    ans+=r-l+1;
   }
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