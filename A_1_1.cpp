/*
Author: Pratyaksh Rai
Date: 2026-03-08
Time: 23:08:58
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

        we have a binary string of length n 

              in one operation we can choose any i 
              such that it is in between two ones 
               

              like 1 i 1 typo thing 

              and we can convert that i into either 0 or 1 

        we have to tell minimum and the maximum number of 1s that can be in the resulting 
        string ? 


*/

// Small Observatins
/*

        so the obj is  , we can even select any set bit or unset bit 
        which is in between two ones , right ? 




*/
//Your attacks
/*

      to mai kya karunga  , sabse pahale 1 ki redi lagaunga , 
      like if possible i will first try to make maximum consecutive ones possible  

      like  11111001111111
      then ill get the maximum number of ones 

      and then after ill make them alternate 101010 typo thing 



*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n;cin>>n;
   string s;cin>>s;
   int mx=0;
   for(int i=1;i<n-1;i++){
    if(s[i-1]=='1'&&s[i+1]=='1')s[i]='1';
   }
   mx=count(s.begin(),s.end(),'1');
  //  cout<<mx<<s<<endl;;
  int mn=0;
  for(int i=1;i<n-1;i++){
     if(s[i-1]=='1'&&s[i+1]=='1')s[i]='0';
  }
  mn=count(s.begin(),s.end(),'1');
  cout<<mn<<" "<<mx<<endl;;
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