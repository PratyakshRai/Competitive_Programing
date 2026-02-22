#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
ek bomb hai jiska timer initially b par set hai , 0 hote hi bomb phat jayega , ab hame bomb ke timer ko delay karana hai 

hamare pass n tool hai har ek tool ek baar hi use ho sakta hai , if you use ith tool the timmer will increase by xi, but if the timer changer to >a the timer will be set to a 

min (c+xi, a );
to c+xi ko minimize karna hai 

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
   int a,b,n;cin>>a>>b>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   sort(arr.begin(),arr.end());
   int ans=0;
   ans+=b-1;
   for(int i: arr){
    int temp=min(i+1,a);
    ans+=temp-1;
   }
   cout<<ans+1<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}