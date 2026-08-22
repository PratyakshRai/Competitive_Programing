/*
Author: Pratyaksh Rai
Date: 2026-04-05
Time: 00:59:34
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

      we have to construct a sequence a containing n integersde 

      such that gcd(a,ai+1) is distince over all 
      can we construct an array 
      where gcd are 1 2 3 4 5 6 7 8 ...
      ? 
      if all gcd are distinct 
      it means for a length of n=10^4 , 
      there exists different gcd is equal to  n-1 distince 
      gcd  

      we have 2.4×10^16​ this much prime no 
      we will first take all the starting prime no 
      and then multiple the other prime no from the end of from n+1 
      to ai , ai+1 
      this will be the best ? right ? 


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
const int N=1e7+5;
bool isprime[N];
vector<int>prime;
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
    int n;cin>>n;
    vi ans(n);
    int idx=0;
    for(int i=0;i<n;i++)ans[i]=prime[idx++];
    idx++;
    for(int i=1;i<n;i++){
      ans[i]*=prime[idx];
      ans[i-1]*=prime[idx];
      idx++;
    }
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
   
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<N;i++)isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=N;i++){
      if(isprime[i]){
      for(int j=i*i;j<=N;j+=i)isprime[j]=false;
    }
    }
    for(int i=2;i<N;i++){
      if(isprime[i])prime.pb(i);
    }
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