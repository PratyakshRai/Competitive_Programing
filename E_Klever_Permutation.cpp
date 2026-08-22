/*
Author: Pratyaksh Rai
Date: 2026-03-24
Time: 22:25:22
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

    n and k 

    k is even 

    k<=n 

    construct k level permutation of length n 
    i think i should construce it in such a way that  

    the s will be 0 1 0 1 0 1 0 1 , like if one dec , then in next one increase 


*/

// Small Observatins
/*

*/
//Your attacks
/*

      we cant take consecutive elements  right? 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
  int n, k;cin>>n>>k;
  vi a(k);
  int l=1,r=n;
  int jmp=(n+k-1)/k;
  vi b(n);
  for(int i=0;i<k;i++){
    for(int j=i;j<n;j+=k){
      if(i&1)b[j]=l++;
      else b[j]=r--;
    }
  }

  for(int i:b)cout<<i<<" ";
  cout<<endl;
  // for(int i=0;i<k;i++){
  //   if(i&1){
  //     a[i]=r;
  //     r-=jmp;
  //   }
  //   else {
  //     a[i]=l;
  //     l+=jmp;
  //   }
  // }

  // for(int i=0;i<n;i++){
  //   cout<<a[i%k]<<" ";
  //   if(i&1){
      
  //     a[i%k]--;
  //   }
  //   else {
  //     a[i%k]++;
  //   }
  // }
  // cout<<endl;
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