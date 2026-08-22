/*
Author: Pratyaksh Rai
Date: 2026-04-02
Time: 18:38:39
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


      we have a sequence of n natural number from 1 to 10^12
      
      
      you can modify this seq by performing the following action x times 

      simultaneously remove all numbers at position y 2*y 3*y ...m*y(<=n) remove karenge , n is the length of current sequence , 

      note we are removing numbers at position y 2*y , .... 


      now we have to find the kth number in the remaining sequence or determine that the length of 
      the remainging seq is less than k 

      what i can do is first get all the numbers which are meant to be deleted at position y first 
      then if x>=y 
      all the numbers which are >=y will be deleted (not actually all  we have to check the remainder things ) and we have to just find the kth element , if 
      k > y-1 ,then put -1 

      what if x<y if k is less than y then no issue after all 


      final sequence me kitne elements bachenge ye bhi pta chal gya 

      now how should i know the kth element ? 
      we will find out , ek move me kitna aage bad rha hai ? 


      k se pichhe y se kitne elements hai utna aage 

      what is the problem now  ? 

      how to find the number ?  , i know how many are left after x operation , how should i 
      know what number is that 


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
There is always a simpler solution for the question 
*/
int x,y,k;cin>>x>>y>>k;
int l=1,h=1e18;
int ans=1e18;
while(l<=h){
  int m=(l+h)/2;
  int temp=m;
  for(int i=0;i<x;i++){
    if(temp==0){
      break;
    }
    temp=temp-temp/y;
  }
if(temp >= k){
    if(temp==k)ans = m;
    h = m - 1;
}
else if(temp<k){
  // if(temp==k)ans = m;
    l = m + 1;
}
// else {
//   cout<<m<<endl;return;
// }
  
}
if(ans>1e12){
cout<<"-1\n";return;
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