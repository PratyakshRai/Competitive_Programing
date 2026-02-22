#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek exam me n different question puchhega 
ab questions ki list ban rhi hai , m list bni , 
har list me n-1 questions hai , aur ek question jo nhi hai wo us list ke number ke equal hai 
if list no 3 hai , to usme 3no wala question nhi hoga 

ab tumhe ek list di jayegi , aur tume us list ke sabhi questions ka answer btana hai ,

tum sirf k questions ka anwer jante ho 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 agar ek se jade element nhi hai , matlab , agar lenght of q : 
 1 . n rha to  111111
 2. n-1 rha to calculate karna padega 
 3. n-2 rha to 00000000

 n-2 ke liye wo i , ie i!= q wale pe 1 hoga 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n, m, k;cin>>n>>m>>k;
   vector<int>arr(m);
   vector<int>q(k);
   for(int &i:arr)cin>>i;
   for(int &i:q)cin>>i;
   if(k==n){
    string ans=string(m,'1');
    cout<<ans<<"\n";return;
   }
   else if(k<=n-2){
    string ans =string(m,'0');
    cout<<ans<<"\n";return;
   }
   int c=0;
   int i;
   c=k+1;
   for( i=0;i<k;i++){
    if(i+1!=q[i]){c=i+1;break;}
   }
   
   for(int i=0;i<m;i++){
    if(arr[i]==c)cout<<"1";
    else cout<<"0";
   }
   cout<<'\n';
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