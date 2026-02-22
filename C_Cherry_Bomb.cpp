#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
do array hai , a aur b of size n  
do no complimentary hai like a[i]+b[i]=x for all i 

ab two interger diye gaye hai a aur b , non negative integer hai , but not greater than k 

ab do array diye gye the , aur b me kuch missing elements hai   , 
ab hame ye btana hai ki no of possible arrays of b such that  a and b  are complementary and the lost elements are replaced by non negative integer no more than k 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 observation : 
 agar do element me jinme -1 nhi hai aur unka sum different aaya to phir us array ka no of array 0 hoga 
 like no of non -1 count karenge aur aur un pair ka sum same nhi hua to 0 other wise phir check karenge



 save last sum and if last sum is not equal to current sum , then -1 
 if current sum > k+a[i] where b[i] is -1 then 0 


 multiple answer usi ke case me hai jha sare -1 hai , 
 us case me max kya hoga 


*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n,k;cin>>n>>k;
   vector<int>arr(n),brr(n);
   for(int &i:arr)cin>>i;
   for(int &i: brr)cin>>i;
   int ones=count(brr.begin(),brr.end(),-1);
   if(ones<n){
    int past=-1;
    for(int i=0;i<n;i++){
      if(brr[i]==-1)continue;
      if(past==-1){
        past=arr[i]+brr[i];
      }
      else {
        if(past!=arr[i]+brr[i]){
          cout<<"0\n";return;
        }
      }
    }
    for(int i=0;i<n;i++){
      if(brr[i]==-1&&(arr[i]>past||(arr[i]<past&&arr[i]+k<past))){
        cout<<"0\n";return;
      }
    }
    cout<<"1\n";return;
   }
   int mx=*max_element(arr.begin(),arr.end());
   int mn=*min_element(arr.begin(),arr.end());
   if(mx>mn+k){
    cout<<"0\n";return;
   }
   else cout<<mn+k-mx+1<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}