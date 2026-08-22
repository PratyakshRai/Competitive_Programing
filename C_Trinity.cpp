/*
Author: Pratyaksh Rai
Date: 2026-03-05
Time: 22:04:03
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
       we can choose any two element  give one of the element the value of the other 

       we have to minimize the number of operation such that the following condition 
       statisfies 

       for every three different triplits there exits a non degenerrate triangle 
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
   int n;cin>>n;
   vi a(n);
   invec(a);
   sort(all(a));
  //  for(int i:a)cout<<i<<" ";
  //  cout<<endl;
  int ans=n;
  for(int i=0;i<n-1;i++){
    int left=i+1,right=n-1,ind=i+1;
    while(left<=right){
      int mid=(left+right)/2;
      if(a[i]+a[i+1]>a[mid]){
        ind=mid;
        left=mid+1;
      }
      else right=mid-1;

    }
    ans=min(ans,n-(ind-i+1));
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