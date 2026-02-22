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
int gcd (int a  , int b){
  while(b!=0){
    int temp=a%b;
    a=b;
    b=temp;
  }
  return a;
}
int lcm (int a , int b ){
  return a*b/gcd(a,b);
}
void Chal_Ja_Plz(){
   int n ;cin>>n;
   vi arr(n);
   invec(arr);
   int  z=1;
   for(int i = 0 ; i< n;i ++){
    z=lcm(z,arr[i]);
   }
   int sum  =0;
   for(int i=0 ;i<n;i++){
    sum+=z/arr[i];
   }
   if(sum<z){
    for(int i=0;i<n;i++){
      cout<<z/arr[i]<<" ";
    }
    
   }else cout<<"-1";
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