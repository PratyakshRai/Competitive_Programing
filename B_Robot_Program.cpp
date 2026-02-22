#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
coordinate line hai aur ek robot hai , 
initially robot zero pe nhi hai ie x!=0


*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 pahale ham zero par maan ke dekhenge ki wapas zero kitne second me aa rha hai , agar aa gya to theek hai , agar nhi aaya to bhi theek hai 


 uske baad ham current se dekhenge ki zero kab tk jaa rha hai  
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*
jab bhi l r typo shit aaye ek baar prefix sum bhi sooch lena , accha rahta hai , soochna , cheeje bhulo nhi , jaruri hoti hai 


*/

 
void Chal_Ja_Plz(){
   int n,x,k;cin>>n>>x>>k;
   string s ; cin>>s;
  vector<int>arr(n);
  if(s[0]=='L')arr[0]=-1;
  else arr[0]=1;
  for(int i=1;i<n;i++){
    arr[i]+=arr[i-1];
    if(s[i]=='L')arr[i]+=-1;
    else arr[i]+=1;

  }
  bool zero=false;
  int st2=0;
  for(int i=0;i<n;i++){
    if(x+arr[i]==0){
      st2=i+1;
      break;
    }
  }
  if(st2==0){
    cout<<"0\n";
    return;
  }
  int ans =1;
  k-=st2;

  int zeroidx=0;
  for(int i=0;i<n;i++){
    if(arr[i]==0){
      zeroidx=i+1;
      break;
    }
  }
  int st1=0;
  if(zeroidx!=0)st1=k/zeroidx;
  ans+=st1;
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