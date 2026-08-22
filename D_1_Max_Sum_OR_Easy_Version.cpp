/*
Author: Pratyaksh Rai
Date: 2026-04-04
Time: 20:51:03
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
#define setbits(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define invec(v) for(int &i : v) cin >> i;
// Common constants
const int INF = 1e18;
const int MOD = 1e9 + 7;

// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Problem Statement
/*

        l is 0 and r < 2.10^5 

          l==r possible 

          n = length of (l,r)

          inshort  , we are given 

          permutation b which is 
          0 1 2 3 4 ...r 

          and another same permutation 
          of same as of b 

          we have to 

          reorder a such that 
          we get maxmum 

          of 

          summation of ai|bi


          maximum possible value tb hogi jb ham  or ka maximum fayda uthayeinge  , right 

          agar ek bhi jagah ai|bi me same bit par 1 hua , to 
          kahi na kahi hamara same ya loss hoga hi hoga , right ? 

          agar number complete 1's me ho like 111111 rhe 
          tb to ulta karke chep do , wahi maximum hoga ? 
          usse adhik to bna hi nhi sakte hai ? right ? 
          i think i even didnt need the loop  right ? 

          like for a given number , i will find out 
          max utilization 
          like for 15 , 1111, i can use till 0 
          as invert of 15 is 0000
          and i will use 16 number and can form 15 
          hence , total =15*16

          but for 9 , 1001
          firt interval will be , invert of 9 
          ie 0110 ie 6 , till six i can use 1111
          4*15 =60 
          then second is 5  0101, invert will be 
          0010 which is 2 
          hence i can use 111 till 4 , is 7*4=28 

          then third will be 1 , invert 0 
          hence  i can use 1 for 1*2  =2 
          and 
          total wil be 60+28+2 = 9 
          and hence we got our number  , happy
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
int maxi(int t){
  if (t==0)return 0 ; 
   t=64-clz(t);
 
  t=((1LL<<t))-1;
  return t;
}
int invert(int x ){
if(x==0)return 0 ;
int bits=64-clz(x);
int mask=(1LL<<bits)-1;
return x^mask;

}

void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
   int l,r;cin>>l>>r;
   vi ans(r+1);
   int tot=0;
   int curadder=maxi(r);
   while(r>=0){
    int L=invert(r);
    int R=r;
    int t=r;
    for(int i=L;i<=R;i++){
      ans[i]=t--;tot+=curadder;
    }
    r=--L;
    curadder=maxi(r);
   }
   cout<<tot<<endl;
   for(int i: ans)cout<<i<<" ";
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