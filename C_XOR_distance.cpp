/*
Author: Pratyaksh Rai
Date: 2026-03-10
Time: 16:06:32
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

    so we have a , b   and  r 
      
    
    we have to find 
    the smallest value of


    abs(a^x -b^x)

    among 0<=x<=r 

    r is about 10^18 
    so we cant do O(r)


    let A= a^x   , B=b^x

    so technically we have to make both the numbers 
    close as possible 

    if x has ith bit 0 nothing gonna happens 
    if x has ith bit 1  , we can do some operations 

    we have to distribute the weight typo thing  , 





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
/*
Always try to optimize your approach
*/
int a,b,r;cin>>a>>b>>r;


      if(a<b)swap(a,b);

  
        int idx = 63 - __builtin_clzll(a ^ b);
      // for(int i=0;i<63;i++){
      //   if((1LL<<i)&r)idx=i;
      // }
      int x=0;
      bool f=true;
      for(int i=idx-1;i>=0;i--){
      {
          int A=(a>>i)&1;
          int B=(b>>i)&1;
         
          int bit=1LL<<i;
          if(A==B)continue;
          //  if(f){
          //   f=false;
          //   continue;
          // }
          if(A){
            if((x|bit)<=r)
            x=(x|(1LL<<i));
          }
        }
      }
      cout<<abs((a^x)-(b^x))<<endl;;
   
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