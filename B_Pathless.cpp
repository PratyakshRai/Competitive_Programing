#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array hai jisme 0,1,2 and an integer s hai ,
at leat ek 0,1,2 to hoga hi

ab alice index 1 se le ke n tak chalegi , wo ya to 1 age chal sakti hai ya ek peeche , jo raste me ayega usko wo add karlegi 
end me S sum usko bnana hai , aur hame use S sum bnane se rokna hai , uske liye hame raste me rakhe gaye values ko idhar udhar rakhna hoga


*/
 
// Small Observatins
/*
agar 1 se le ke n tak ka sum ==k aaya to ans -1
agar 1 se leke n tak ka sum > k aya to simple array ko print kar dena 

ab case banta hai sum<k ho : 



*/
 
 
//Your attacks
/*
 when sum <k
 agar 0 aur 1 ek saath hai like 0 , 1 ya phir 1 , 0 to koi bhi combination ban sakta hai ex: 
  (.....ye sum manlo s0 hai ) 0 1 (...... ye sum manlo s1 hai ) nth 
  to k-s0 -s1 = x to x ko to ham generate hi kar sakte hai 0 aur 1 x time ocillate kara ke               
  similarly 1 aur 1 ek saath ho tb 
    (.....ye sum manlo s0 hai ) 1 1 (...... ye sum manlo s1 hai ) nth 
    is case me agar x odd hua to -1 
    (.....ye sum manlo s0 hai ) 1 1 1  (...... ye sum manlo s1 hai ) nth 
    is case me agar x even hua to -1 

*/
 
 
// Hints From Code 
/*  
jaha nhi banna chahiye wha bhi bna de rha hai 

 
*/
 
 
// Learn form question
/*

toda sa sahi sooch liya tha , bass end me -1 kab hoga ye nhi soch paya 

ye soochna chahiye tha ki 
: 
sabase pahale k-sum dekhna chahiye tha ki kab nhi bann payega 

wo k-sum ==1 wala part to nhi kar pata but 70% problem solve karli thi 

*/
 
 
void Chal_Ja_Plz(){
   int n,k;cin>>n>>k;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   int sum =accumulate(arr.begin(),arr.end(),0LL);
   if(sum==k){
    cout<<"-1\n";return;
   }else if (sum>k){
    for(int i: arr)cout<<i<<" ";
    cout<<"\n";return;
   }
   int one =count(arr.begin(),arr.end(),1);
   int two=count(arr.begin(),arr.end(),2);
   int z=n-one-two;
   vector<int>b;
   for(int i=0;i<z;i++)b.push_back(0);
   for(int i=0;i<two;i++)b.push_back(2);
   for(int i=0;i<one;i++)b.push_back(1);
   int d=k-sum;if(d==1){
    for(int i: b)cout<<i<<" ";
    cout<<"\n";return;
   }
   else cout<<"-1\n";

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}