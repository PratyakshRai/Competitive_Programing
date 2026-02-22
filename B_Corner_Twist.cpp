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
#define invec(v) for(auto  &i : v) cin >> i;
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
  int n , m ;cin>>n>>m;
  vector<string>a(n),b(n);
  invec(a);
  invec(b);
  auto process=[&](int i , int j ){
    int difference =(b[i][j]-a[i][j]+3)%3;
    if(difference==0)return;
    else if(difference==1){
        a[i][j]=(a[i][j]-'0'+1)%3+'0';
        a[i+1][j+1]=(a[i+1][j+1]-'0'+1)%3+'0';
        a[i][j+1]=(a[i][j+1]-'0'+2)%3+'0';
        a[i+1][j]=(a[i+1][j]-'0'+2)%3+'0';
    }
    else {
        a[i][j]=(a[i][j]-'0'+2)%3+'0';
        a[i+1][j+1]=(a[i+1][j+1]-'0'+2)%3+'0';
        a[i][j+1]=(a[i][j+1]-'0'+1)%3+'0';
        a[i+1][j]=(a[i+1][j]-'0'+1)%3+'0';
    }

  };
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m-1;j++){
        process(i,j);
    }
  }
  cout<<(a==b?"YES":"NO")<<endl;

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