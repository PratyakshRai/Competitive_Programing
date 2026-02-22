#include<bits/stdc++.h>
using namespace std;
#define int long long
 //ye question kyu nhi hua
/*
 bahut zade complecate kar rha tha 
 ek hi saath kai cheeje chal rhi thi man me 
 ek clear vision nhi mill pa rha tha 
*/
// Problem Statement
/*
ek array hai b , m length ki , wo awesome hai kab ? 
if(i is odd then bi<bi+1)
else (i is even then bi>bi+1)

b1<b2>b3<b4....

ab ek array di jayegi n length ki aur uspe  following operation kar sakte ho : 

operation kya hai : 
1: ek i select karo aur ai=max(a1,a2,,,,ai); kardo 
2: ek i lo aur ai-- kardo 

ab btao minimum number of times you need to do operation 2 to make a awesome , you dont need to minimize operation 1; 


*/
 
// Small Observatins
/*
mera pass do tarike hai , dono me jo minimum answer ayega usko choose karunga 
tarika no 1: 
b1<b2 ye case hai : 
to chahe jo ho jaye , like b1 actually me b2 se bda ho ya b1 b2 se chhota ho 
agar maan lo b2 b1 se bda hai to bhi use max se replace kar denge , taki future me use hoye max 
agar 


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
   vector<int>arr(n);
   for(int &i :arr)cin>>i;
  int mx=-1;
  for(int i=0;i<n;i++){
    if(arr[i]>mx)mx=arr[i];
    if(i%2!=0)arr[i]=mx;
  }
  int ans=0;if(n>2){
  for(int i =2;i<n-1;i+=2){
    if(i<n-1){
      int diff=min(arr[i+1]-arr[i],arr[i-1]-arr[i]);
      if(diff<=0)ans+=abs(diff-0)+1;

    }
  }}
  int first=arr[1]-arr[0];
  if(first<=0)ans+=abs(first-0)+1;
  if(n%2!=0&&n>2){
    int second=arr[n-2]-arr[n-1];
    if(second<=0)ans+=abs(second-0)+1;
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