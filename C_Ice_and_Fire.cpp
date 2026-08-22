/*
Author: Pratyaksh Rai
Date: 2026-03-29
Time: 16:17:27
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

        n player , temperature values of i player is  i 

        environment is either 0 or 1 

        0:lower temp always wins
        1:higher temp always wins 

        n-1 length binary string representing environement 
        if x players are there , x-1 battles will be their 
        x-1 types of environment will be there 


        choose any two remianing players to fight 


        for each x from 2 to n , 
        answer : 
        if all playhers whose temperature values does not exceed 
        x participate in the game , how many players have a chance to win ? 



*/

// Small Observatins
/*

*/
//Your attacks
/*

      kab mere pass options nhi rahenge ? 

      let if there is x 
      and the string is all 00000 or all 111111 
      
      so what will happen 

      for each round there will one eliminate and no further 
      options are created , rigth ? 

      highest , aur lowest ka use kar sakte hai 
      like 1 and x for each round ? right ? 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
   int n;cin>>n;
   string s ;cin>>s;
   int cnt=0;
   int prev=-1;
   int cur=0;
   for(int i=0;i<n-1;i++){
    cnt++;
    if(prev==-1){
      
      cout<<cnt<<" ";
      cur=cnt;
    }
    else if(s[i]-48==prev){
      cout<<cur<<" ";
    }
    else {
      cout<<cnt<<" ";
      cur=cnt;
    }
    prev=s[i]-48;
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