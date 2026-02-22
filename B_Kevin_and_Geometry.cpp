#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
there is n sticks
kevin want to select 4 sticks to form trapezoid isosceles , with a positive area 
note that rectange and square are also consider to be as trapezoid 

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
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   int flag=true;
   set<int>st;
   int side=0;
   sort(arr.begin(),arr.end());
   for(int i=n-1;i>=0;i--){
    if(st.count(arr[i])){
      side=arr[i];
      flag =false;
      break;
    }
    else st.insert(arr[i]);
   }
   if(flag){
    cout<<"-1\n";return;
   }
   vector<int>b;
   int cnt=2;
   for(int i=n-1;i>=0;i--){
    if(arr[i]==side){
      if(cnt<=0)b.push_back(arr[i]);
      else cnt--;
    }
    else b.push_back(arr[i]);
   }
   for(int i=0;i<b.size()-1;i++){
    int diff=b[i]-b[i+1];
    if(diff<2*side){
      cout<<side<<" "<<side<<" "<<b[i]<<" "<<b[i+1]<<"\n";
      return;
    }
   }
cout<<"-1\n";
return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}