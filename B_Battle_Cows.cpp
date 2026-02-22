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
int check (int idx , vector<int>&a){
  int n=a.size();
  int res=0;
  if(idx!=0)res++;
  for(int i=idx +1;i<n;i++){
    if(a[i]>a[idx])break;
    res++;
  }
  return res;
}
void Chal_Ja_Plz(){
   int n, k;cin>>n>>k;
   k--;
   vi arr(n);
   invec(arr);
   swap (arr[0],arr[k]);
   int ans=check(0, arr);
   swap (arr[0],arr[k]);
   for(int i=0;i<k;i++){
    if(arr[i]>arr[k]){
      swap(arr[i],arr[k]);
      ans=max(ans, check(i, arr));
      break;
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