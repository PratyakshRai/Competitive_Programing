#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek array di gai hai , uska score define hota hai , length - no of distinct elements in it 
i.e score -ve bhi ho sakta hai 

you have to delect some subarray so that score is maximum and length is minimum 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 score : length - no of distinct elements

 score ko  maximise karna hai , uske liye ham jo bhi elements choose kar rhe hai koshish ye rahe gi ki unme se koi bhi repetitive na ho other wise length kam hogi, ab maanlo hame ek score mill gya hai , 
 jo ki maximum tha ab isme length ko mimizise kaise karenge ? 
 a

*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   vector<int>freq(n+1);
   vector<int>len(n+1);
   for(int i:arr)freq[i]++;
   len[0]=freq[arr[0]]==1;
   for(int i=1;i<n;i++){
    if(freq[arr[i]]==1){
      len[i]=len[i-1]+1;
    }
   }
   int mx=*max_element(len.begin(),len.end());
   if(mx==0){
    cout<<"0\n";
    return;
   }
   for(int i=0;i<n;i++){
    if(len[i]==mx){
      cout<<i-len[i]+2<<" "<<i+1<<"\n";
      return;
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