/*
Author: Pratyaksh Rai
Date: 2026-03-27
Time: 22:53:54
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

      we can do cycle shift any number of times 
      we have to find the maximum matching pairs of elements 

      both the arrays will be in permutations 
      we cant do n^2 


*/

// Small Observatins
/*

*/
//Your attacks
/*

      ek ek baar cycle shift kare agar , 
      par how to check for same element without using 
      full iteration

      kaun kaun brabar hai use kam se kam time complexity me ka
      kaise kare ? 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
int n;cin>>n;
vi a(n);
invec (a);
vi b(n);
vi pos(n+1);
for(int i=0;i<n;i++){
  cin>>b[i];
  pos[b[i]]=i;
}
vi counts(n,0);
for(int i=0;i<n;i++){
  int target=pos[a[i]];
  int shift=(target-i+n)%n;
  counts[shift]++;
}
int mx=0;
for(int i:counts)mx=max(mx,i);
cout<<mx<<endl;

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; t=1;
    while (t--) Chal_Ja_Plz();
    return 0;
}
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/