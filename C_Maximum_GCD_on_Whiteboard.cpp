/*
Author: Pratyaksh Rai
Date: 2026-02-23
Time: 15:30:08
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
bool can(vector<int>&arr,int n, int k , int g){
  for(int i=0;i<n;i++){
  if(arr[i]%g==0)continue;
  int t=arr[i]/g;
  if(t<4){
    if(k==0)return false;
    else k--;
  }  
  }
  return true;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n,k;cin>>n>>k;
vector<int>freq(n+1,0);
for(int i=0;i<n;i++){
  int x;cin>>x;
  freq[x]++;
}
for(int i=1;i<=n;i++)freq[i]+=freq[i-1];
for(int g=n;g>=1;g--){
  int pos=freq[min(n,4*g-1)];
  pos-=freq[g]-freq[g-1];
  if(2 * g <= n) pos-=freq[2*g]-freq[2*g-1];
  if(3*g<=n)pos-=freq[3*g]-freq[3*g-1];
  if(pos<=k){
    cout<<g<<endl;
    return;
  }
}
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