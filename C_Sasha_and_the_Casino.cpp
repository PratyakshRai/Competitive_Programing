/*
Author: Pratyaksh Rai
Date: 2026-03-24
Time: 23:10:55
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

          if you places bet of y coins 

          then in case of winning you will get y.k coins 

          ie profit is y.(k-1)

          in case of losing you will loose 
          the entire bet , ie y 

          the bet amount must be positive no ie >0 
          and cannot exceed shasha's current no of coins 

          also he cannot loose more than x times in a row


          we have to prove that , if you have a coins 

          and you place bets such that he is guaranteed to win any number of coins 

          is it true that for any integer n sasha can make bets so that for any outcome , he will have at least n coins 




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
int k,x,a;cin>>k>>x>>a;

int currmoney=a;
int loss=0;
for(int i=0;i<=x;i++){
  int t=k-1;
  int bet=loss/t +1;
  if(bet>currmoney){
    NO;return;
  }
  loss+=bet;
  if(loss>a){
    NO;return;
  }
  currmoney-=bet;
}
YES;

// a-=x;
// if(a<=0){
//   NO;
//   return;
// }
// if((k-1)*a>x){
//   YES;return;
// }
// if(x<a&&(k-1)>=x){
//   YES;
// }

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