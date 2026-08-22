/*
Author: Pratyaksh Rai
Date: 2026-03-25
Time: 22:49:23
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

        k is given , the beauty is the summation of floor of ai/k 
            n is also given

        for a given k , 
              b is also given , and sum of the elements is also 
              given 

        so b<=sum       


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
int n,k,b,s;cin>>n>>k>>b>>s;
if(k*b>s){
  cout<<"-1\n";return;
}
vi ans(n);
ans[0]=k*b;
s-=k*b;
ans[0]+=min(k-1,s);
s-=min(k-1,s);
for(int i=1;i<n;i++){
  if(s>0)
  {ans[i]= min(s,k-1);
  s-=min(s,k-1);}
}   
if(s>0){
  cout<<"-1\n";return;
}
for(int i :ans)cout<<i<<" ";
cout<<endl;;

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