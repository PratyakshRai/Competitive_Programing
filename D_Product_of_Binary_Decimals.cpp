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
ek number hai usko kuchh binary notation wale number ke format me likhna hai 
to kya se possible hai ya nhi ? 
*/

// Small Observatins
/*
phala digit hamesha 1 hona chahiye , 
aur akhiri 0 ya 1 
*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/vector<int>arr;
bool ok(int n ){
  if(n==1)return true;
  bool ans=false;
  for(int i: arr){
    if(n%i==0){
      ans|=ok(n/i);
    }
  }return ans;
}

void Chal_Ja_Plz(){
  int n;cin>>n;
  if(ok(n))YES;
  else NO;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=1e5;i++){
      int t=i;
      bool flag=true;
      while(t){
        if(t%10>1){
          flag=false;
          break;
        }
        t/=10;
      }
      if(flag)arr.push_back(i);
    }
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