/*
Author: Pratyaksh Rai
Date: 2026-03-03
Time: 22:55:26
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

      we have some cards  ,each card has some int on it 

      like for each i you have ai cards , and i is written on it 

      now there is shop which has unlimited no of cards of each type 

      you have k coins  so you can buy k new cards in total 
      you can buy cards 1 to n written on it 

      after buying new cards you rearrange all those cards 

      the score of rearrangement is the number of contiguous subarray 
      of length n which are a permutation of n ? 
      what is the max length you can get ? 

          so we have to maximize the number of subarray of which contains permutation 
          of length n 

          like the length should be n , obiously 

          i will first try to distribute the cards 
          so that the number of permutation become max
          but  how? 

          how to make that permutation max possible ? 

          first i'll try to make them equal to maximum 
          
          among them ill prioritize the last and first cards if possible
          


*/
// Hints From Code 
/*  

*/
bool check (int mid, int n , int k, const vector<int>&a){
  int required =0; 
  for(int i: a){
    if(i<mid)required+=mid-i;
    if(required>k)return false;
  }
  return required<=k;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n, k;cin>>n>>k;
vi a(n);invec(a);
int low=0,high=2e12;
int w=0;
while(low<=high){
  int mid=low+(high-low)/2;
  if(check(mid,n,k,a)){
    w=mid;
    low=mid+1;
  }
  else high=mid-1;

}
int used=0;
for(int x:a)if(x<w)used+=w-x;
int left=k-used;//kitne card bache hai abhi 
int cnt=0;
for(int x :a)if(x<=w)cnt++;//kitne card ko bdaba hai ? 

cnt-=left;

// n*w -(n-1)+(n-cnt) lol 
cout<<n*w-cnt+1<<endl;

   
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