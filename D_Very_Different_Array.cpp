/*
Author: Pratyaksh Rai
Date: 2026-01-10
Time: 22:25:20
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
void Chal_Ja_Plz(){
   int n,m;cin>>n>>m;
   vector<int>arr(n);
   invec(arr);
   sort(all(arr));
   multiset<int>brr;
   for(int i=0;i<m;i++){
    int x;cin>>x;
    brr.insert(x);
  }
 
  int ans=0;
  int i=0, j=n-1;
  while(i<=j){
    int smol=*brr.begin();
    int larg=*brr.rbegin();
    if(abs(arr[i]-larg)>abs(arr[j]-smol)){
      
      ans+=abs(arr[i]-larg);
      brr.erase(prev(brr.end()));
      i++;
    }else {
     
      ans+=abs(arr[j]-smol);
      brr.erase(brr.begin());
       j--;
    }
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