/*
Author: Pratyaksh Rai
Date: 2026-03-27
Time: 19:35:48
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

      two guys play a game 

      they started with a number n and play in turns , 

      in each turn a player can make any one of the following moves

      divide n by any of its odd divisors greater that 1 
      or 
      substract 1 from n if n is greater that 1 

      divisor of a number includes the number itself 

      the palyer who is unable to make moves loses the game

      A moves first 

      determine the winner ? it both play optimally ? 





*/

// Small Observatins
/*

*/
//Your attacks
/*


    any guy  , when he will loose ? 

    if the numeber is 1 or 
    the number is power of 2  , like there will never be any odd divisors then 

    case 1 : if a number is given ,
                                  if it is odd 
                                  then A will use that odd 
                                  number and A will will
    
                                  
      case 2: if  the numeber is not odd : 

            it means it is even 
            if it is even  , then 
            it means it has some even numbers 
            and may be some odd numbers 

            if it has some even numbers only then 

            A has to substract only , and then it becomes odd 
            and then B will win 

            if it has some odd numbers also , then a will 
            took all those odd numbers and then 
            B will has to substract only , and hence 
            A will win 
      

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
int n;cin>>n;
if(n==1){
  cout<<"FastestFinger\n";return;
}
if(n==2){
  cout<<"Ashishgup\n";return;
}
if(n%2!=0){
  cout<<"Ashishgup\n";return;
}
if((n&(n-1))==0){
    cout<<"FastestFinger\n";return;
}
if(n%4==0){
    cout<<"Ashishgup\n";return;
}

int cnt=0;
set<int>st;
for(int i=2;i*i<=n;i++){
  if(n%i==0){
    if(i%2==1)st.insert(i);
    if((n/i)%2==1){
      if((n/i)!=i)st.insert(n/i);
    }
  }
}
if(st.find(1)!=st.end())st.erase(1);
// for(auto it :st)cout<<it<<" ";
// cout<<endl;
if(st.size()==1){
   cout<<"FastestFinger\n";return;
}
   cout<<"Ashishgup\n";return;
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