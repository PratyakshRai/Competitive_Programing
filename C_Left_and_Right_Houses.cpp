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
   int n;cin>>n;
   string s;cin>>s;
   vector<int>arr(n+1);
   for(int i=0;i<n;i++){
    arr[i+1]=arr[i]+(s[i]=='0');
   }
   
   vector<int>brr(n+1);
   for(int i=0;i<n;i++){
    brr[i+1]=brr[i]+(s[i]=='1');
   }
 int ans = -1;

for (int x = 0; x <= n; x++) {
    if (arr[x] >= (x + 1) / 2 &&
        brr[n] - brr[x] >= (n - x + 1) / 2) {

        if (ans == -1 ||
            abs(2*x - n) < abs(2*ans - n)) {
            ans = x;
        }
    }
}

cout << ans << endl;
   
  //  if(ans==n)cout<<"0\n";
  //  else cout<<act<<endl;
   
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