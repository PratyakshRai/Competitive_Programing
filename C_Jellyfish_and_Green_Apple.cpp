/*
Author: Pratyaksh Rai
Date: 2026-03-04
Time: 22:08:45
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
      har ek cut me ek extra add ho rha hai 
      manlo 
      3 tha pahale  , to ek cut ke baad 4 then ek aur cut ke baad 5 

      ab baat ye hai ki ham  x no of cut lga to lenge , but 
      wo equal ho , ye kaise nikalu

      odd no me kabhi bhi brabar nhi distribute kar sakte ho 
      1/5 1/7 1/3 , kaise laoge ? 
      jab har bar denominator me 2 muliply ho rha hai 
      like 1/2 1/4 1/8 
      its impossible 
      other wise for even 
      its possible
      more refine 
      1/(2 ki power me rhe tabhi possible hai )


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
   int n,m;cin>>n>>m;
   if(n%m==0){
    cout<<0<<endl;
    return;
   }
  
  int t=m/(gcd(m,n));
  if((t&(t-1))!=0){
    cout<<"-1\n";return;
  }
  n=n%m;
  int ans=0;
  while(n){
    if(n>=m)n=n%m;
    else {
      ans+=n;
      n*=2;
    }

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