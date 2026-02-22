/*
Author: Pratyaksh Rai
Date: 2026-02-03
Time: 21:09:19
*/

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
    so if the array already satisfy the conditions ,put x =1 (you can put any number)
    if not 


    then   


           it is mentioned that answer always exits 
           

           can we make smaller value from the starting ? 
           like 1 1 1 ...

           can we iterate backward ? 
           

*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   vector<int>values,val;
   for(int i=0;i<n-1;i++){
    if(arr[i+1]%arr[i]!=0){values.pb(arr[i]/(gcd(arr[i],arr[i+1])));}
   }
  int ans=1;
  for(int i:values){
    ans=i*ans/gcd(i,ans);
  }
     cout<<ans<<endl;
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