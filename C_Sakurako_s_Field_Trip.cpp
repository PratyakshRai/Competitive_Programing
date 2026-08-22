/*
Author: Pratyaksh Rai
Date: 2026-03-05
Time: 16:13:29
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

        dikkat kaha ayegi ? 
        jaha i aur i+1 brabar hai 

        agar i ko swap karenge to 
        swapping jagah pe bhi conflict nhi hona 
        chahiye 




*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n ; cin>>n;
   vi a(n);
   invec(a);
   int cnt=0;
  //  for(int i=0;i<n-1;i++)if(a[i]==a[i+1])cnt++;
   for(int i=n/2-2;i>=0;i--){
    if(a[i]==a[i+1]||a[n-i-2]==a[n-i-1]){
      swap(a[i],a[n-i-1]);
    }
  //  }
  //  if(a[n-2]==a[n-1]){
  //   int i=n-1;
  //    int swpidx=n-1-i;
  //     if(a[swpidx]==a[i]){}
  //     else {
  //     bool flag=true;
  //     if(swpidx+1<n)if(swpidx+1!=i)flag&=(a[swpidx+1]!=a[i]);
  //     if(swpidx-1>=0){
  //     if(swpidx-1!=i)flag&=(a[swpidx-1]!=a[i]);}
  //     if(i+1<n){
  //     if(i+1!=swpidx)flag&=(a[i+1]!=a[swpidx]);}
  //     if(i-1>=0)if(i-1!=swpidx)flag&=(a[i-1]!=a[swpidx]);
  //     if(flag){cnt--;
  //     swap(a[i],a[swpidx]);}
  //   }
   }
  
   cnt=0;
   for(int i=0;i<n-1;i++)if(a[i]==a[i+1])cnt++;
  //   if(n%2==0){
  //   swap(a[n/2],a[n/2-1]);
  //  }
  //  int temp=0;
  //  for(int i=0;i<n-1;i++)if(a[i]==a[i+1])temp++;
  //  cnt=min(cnt,temp);
   cout<<cnt<<endl;
  //  for(int i: a)cout<<i<<" ";
  //  cout<<endl;
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