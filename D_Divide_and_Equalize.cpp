/*
Author: Pratyaksh Rai
Date: 2026-02-17
Time: 13:56:49
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
int nof(int n, int d){
  int res=0;
  while(n%d==0&&n>0){
    n=n/d;
    res++;
  }
  return res;
}
vi primeno;
void add_div(int x , map<int,int>&mp){
  int i=2;
  while(i*i<=x){
    while(x%i==0){
      mp[i]++;
      x/=i;
    }
    i++;
  }
  if(x>1)mp[x]++;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   map<int,int>divs;
   for(int i=0;i<n;i++){
    add_div(arr[i],divs);
   }
   for(auto i : divs){
    if(i.ss%n!=0){
      NO;return;
    }
   }
   YES;

  //  for(int i=0;i<n;i++){
  //   int no=arr[i];
  //   int idx=0;
  //   while(primeno[idx]<=arr[i]){
  //     mp[primeno[idx]]+=nof(arr[i],primeno[idx]);
  //     idx++;
  //   }
  //  }
  //  for(auto it :mp){
  //   if(it.ss!=0){
  //     if(it.ss%n!=0){
  //       NO;
  //       return;
  //     }
  //   }
  //  }
  //  YES;
  //  for(auto it :mp)cout<<it.ss<<" ";
  //  cout<<endl;


  //  int t=*max_element(all(arr));
  // int i=0;
  // // for(int i=0;i<n;i++){
  // //   cout<<nof(arr[i],2)<<" ";
  // // }
  // // cout<<endl;
  // bool flag=false;
  // while(primeno[i]<=(t)){
  //   int cnt=0;
  //   int pp=primeno[i];
  //   for(int i=0;i<n;i++){
  //     cnt+=nof(arr[i],pp);
  //   }
  //   if(cnt!=0&&cnt%n!=0){
  //     flag=true;
  //     break;
  //   }
  //   i++;
  //   // cout<<cnt<<" ";
  // }
  // // cout<<endl;

  // if(flag){
  //   NO;return;
  // }YES;return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  const int N=1e6+5;
 vector<bool>isprime(N,true);
 isprime[0]=isprime[1]=false;
 for(int i=2;i*i<N;i++){
  if(isprime[i]){
    for(int j=i*i;j<N;j+=i){
      isprime[j]=false;
    }
  }
 }
 for(int i=2;i<N;i++){
  if(isprime[i])primeno.pb(i);
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