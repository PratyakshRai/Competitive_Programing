/*
Author: Pratyaksh Rai
Date: 2026-01-28
Time: 19:40:13
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
      let array n =5 , then first we have to check for div of 2 , for this no consecutive odd or even 
      and after div of 3 , 
      12345
      i can do something like  
       1 4 3 2 4 , nope

       nope .

       if n is odd then , we have as a divisor is n , and the summation is
       n*(n+1)/2;
       if n is odd then n+1 is even and 2 will divide this, 
       aur hamara divisor n , n ko divide kardega , so n belogs to odd not possible , what about  if n is even ? 

       1 2 3 4 
       ? 
       for div of 2 , we must put odd even odd even ...
       what if we shit , 
       1 4 3 2   nope 
       what if 2 1 4 3 , yup
       for div of 4 its correct  

       for n=6 1 2 3 4 5 6 

       2 1 4 3 6 5 , 1 4 3 6 5 2  

       5 consecutive integer sum is 
        like x x+1 x+2 x+3 x+4
        5*x + 5 , so it is clear that we cant make consecute elements 
        so that is why we have to swap the digits so that there is no consecutive elements present in the array  , and then we will can define for every div like 3 4 5 6 
         like we can say , 3 se agar koi bhi subarray divide ho rha hai to teen lagatar consecutive element rha hoga atleast , as there are many possebility , 
         so if we swap all the digits there will no consecutive elements be there 
*/
// Hints From Code 
/*
CODE OF EDITORIAL  
*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   if(n==1){
    cout<<1<<"\n";return;
  }if(n&1){
    cout<<"-1\n";return;
  }
  int i=2, j=1;
  for(int k =0 ;k<n/2;k++){
    cout<<i<<" "<<j<<" ";
    i+=2;j+=2;
  }
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