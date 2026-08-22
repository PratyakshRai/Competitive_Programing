/*
Author: Pratyaksh Rai
Date: 2026-03-02
Time: 23:17:05
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
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
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
/*
Always try to optimize your approach
*/
  int n;cin>>n;
  int a[n+1]={0};
    set<int> s; FOR(i, 1, n) s.insert(i);
    // for(int i=1;i<=n;i++)a[i]=i;
   {
    int pos=1;
    while(pos*2<=n)pos*=2;
    if(n&1){
    int low=n&(-n);
    a[n-3]=low,a[n-2]=low+(low==1?2:1),a[n-1]=n-low,a[n]=n;
    cout<<n<<endl;}
    else{
      cout<<pos*2-1<<endl;
      if(n==pos){
        a[n-4]=1,a[n-3]=3,a[n-2]=n-2,a[n-1]=n-1,a[n]=n;

      }
      else {
        a[n-2]=n,a[n-1]=n-1,a[n]=pos-1;
            }
    }
  }
    FOR(i, 1, n + 1) s.erase(a[i]);
    FOR(i, 1, n + 1) if (!a[i]) a[i] = *s.begin(), s.erase(a[i]);
    FOR(i, 1, n + 1) cout << a[i] << " "; cout << endl;
   
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