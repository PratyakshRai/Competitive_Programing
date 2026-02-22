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
array b and size m 
maximum prefix position of array of b 
smallest index that satisfy 
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
   int n ; cin>>n;
   int x , y  ; cin >>x>>y;
   vector<int>arr(n+1);
   int e=-1;
   for(int i=y-1;i>=0;i--){arr[i]=e;e*=-1;}
   for(int i=y;i<=x;i++)arr[i]=1;
   e=-1;
   for(int i=x+1;i<=n;i++){arr[i]=e;e*=-1;}
   
   for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
   cout<<endl;

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