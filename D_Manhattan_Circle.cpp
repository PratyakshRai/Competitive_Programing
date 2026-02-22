#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
to hame nxm grid di jayegi 
manhattan circle diya jayega 
# wale points manhattan circle me aate hai 
h-a+k-b<r circle ka equation hoga 
hame centre btana hai manhattan circle ka

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 simple hai 
 manhattan points save karlenge aur iterate karenge har point se aur check karenge ki koi ayesa point mill rha hai jisse sari conditions satify ho rhi hai ki nhi 

 sabhi points {i,j}ke pair me save karlenge phir n^2 loop lga ke iterate karenge aur ek set bnayenge int,pair<int,int> ka jisme int distance from all other
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
void Chal_Ja_Plz(){
   int n,m;cin>>n>>m;
  int h1=0,h2=0,v1=0,v2=0;
  bool hfound=true,vfound=true;
  vector<vector<char>>arr(n+1,vector<char>(m+1));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      char temp;cin>>temp;
      if(hfound&&temp=='#'){
        h1=i;
        hfound=false;
      }
      arr[i][j]=temp;
      if(temp=='#')h2=i;
    }
  }
  for(int j=1;j<=m;j++){
    for(int i=1;i<=n;i++){
      char temp;temp=arr[i][j];
      if(vfound&&temp=='#'){
        v1=j;
        vfound=false;
      }
  
      if(temp=='#')v2=j;
    }

  }
  int y=abs(v2+v1)/2;
  int x=abs(h2+h1)/2;
  cout<<x<<" "<<y<<"\n";


}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}