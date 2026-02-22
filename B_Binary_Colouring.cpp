#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n' 
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vi vector<int>
#define ff first
#define ss second
#define invec(v) for(int &i : v) cin >> i;
// Common constants
const int INF = 1e18;
const int MOD = 1e9 + 7;

// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Problem Statement
/*

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
void Chal_Ja_Plz(){
   int x;cin>>x;
   vi arr(31,0);
   int last=-1;
   for(int i =0;i<30;i++){
    if(1ll&(x>>i)){
      if(arr[i]){
        arr[i+1]=1;
        arr[i]=0;
      }else if (i>0){
        if(arr[i-1]==1){
          arr[i+1]=1;
          arr[i-1]=-1;
        }
        else {
          arr[i]=1;
        }
      }else if(i==0){
        arr[i]=1;
      }
    }
   }
  cout<<31<<endl;
  for(int i : arr)cout<<i<<" ";
  cout<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/