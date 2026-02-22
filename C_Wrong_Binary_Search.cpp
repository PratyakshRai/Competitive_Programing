#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek string di gayi hai , aur hame ek permutation bnana hai 

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
number swap karne ki technique , mast thi , jis tarah edge case handle kiya , aur clear aur logical code likha kam line me 


*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s;cin>>s;
   vector<int>arr(n);
   iota(arr.begin(),arr.end(),1);
   int flag=true;
   for(int i=0;i<n;i++){
    if(s[i]=='0'){
      if(i&&s[i-1]=='0')swap(arr[i],arr[i-1]);
      else if(i+1==n||s[i+1]!='0')flag=false;
    }

   }
   if(flag){
    cout<<"YES\n";
    for(int &i:arr)cout<<i<<" ";
    cout<<"\n";
   }else cout<<"NO\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}