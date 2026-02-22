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
pahale dono ko sort kardo 
   1 2 2 4
   1 2 2 3 5
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n; cin>>n;
   vi arr(n), brr(n+1);
  for(int &i : arr)cin>>i;
  for(int &i : brr)cin>>i;
  int cnt =0;
  int last =brr.back();
  int diff =1e9;bool flag=false;
  for(int i =0;i<n;i++){
    cnt+=abs(arr[i]-brr[i]);
    if(last<=arr[i]&&last>=brr[i]||last>=arr[i]&&last<=brr[i]){
      flag=true;
    }
    if(diff>min(abs(last-brr[i]),abs(last-arr[i])))diff=min(abs(last-brr[i]),abs(last-arr[i]));
  }
  if(flag){
    cnt++;

  }
  else {cnt+=diff;cnt++;}
  cout<<cnt<<endl;
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