/*
Author: Pratyaksh Rai
Date: 2026-02-28
Time: 12:50:35
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

*/
// Hints From Code 
/*  

*/
const int N=7000900;

vi prime(N+2);
vi prefix;
set<int>st;
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n;cin>>n;
   vi a(n);
   invec(a);
   sort(all(a));
   reverse(all(a));
   vi pr(n+1);
   for(int i=0;i<n;i++)pr[i+1]=pr[i]+a[i];
   int k =0;
   for(int i=1;i<=n;i++){
    if(pr[i]>=prefix[i])k=i;
    else break;
   }
   cout<<n-k<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prime[0]=prime[1]=1;
    for(int i=2;i*i<=N;i++){
      if(!prime[i]){
       
      
      for(int j=i*i;j<=N;j+=i){
        prime[j]=1;
      }
    }
    }
    prefix.pb(0);
    for(int i=2;i<=N;i++)if(!prime[i])prefix.pb(i);
    // for(int i=0;i<N;i++)if(!prime[i])st.insert(i);
    for(int i=0;i<prefix.size();i++)prefix[i+1]+=prefix[i];
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