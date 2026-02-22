#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define end '\n' 
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vi vector<int>
#define ff first
#define ss second
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
so 2x +4y typo shit 
get the range for x and y 
make two loop for it 

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n ;cin>>n;
   int x=n/2;
   int y=n/4;
   int cnt=0;
   for(int i=0;i<=x;i++){
    for(int j=0;j<=y;j++){
      if(2*i+4*j==n)cnt++;
    }
   }
   cout<<cnt<<"\n";
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