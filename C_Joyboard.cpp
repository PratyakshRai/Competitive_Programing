/*
Author: Pratyaksh Rai
Date: 2026-01-28
Time: 20:33:58
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

*/
//Your attacks
/*
      agar hame sare ek saman bnane hai , 
      like for k=1 , we can put n+1 as 1 or n+1 or n+n+ 1 ....
      similarly for 2 , we can say , 
      put 2 or n+2 or n+6 or ....

      k should be less than n 
      or you cant make more than 3 diff elements , as things gonna repeat 


      for distince elements to be 3 
      we must take x > n  also x%n!=0 
      for elements to be 2 
      ie m/k and for(int i=1;i<)..., 
      for elments to be 1 we should take either x as zero 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n, m, k;cin>>n>>m>>k;
   if(k==1){
    cout<<1<<endl;
    return;
   }
   else if(k==2){
    if(m<=n){
      cout<<m<<"\n";
      
    }else {
      cout<<n+m/n-1<<"\n";
    }
   }
   else if(k==3){
    if(m<=n){
      cout<<0<<endl;
    }else{
      cout<<m-(m/n)-(n-1)<<"\n";
    }
   }else cout<<"0\n";

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