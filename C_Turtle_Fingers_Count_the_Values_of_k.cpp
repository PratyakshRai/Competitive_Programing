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
int power(int a , int b){
  int res=1;
  while(b>0){
    if(b&1)res*=a;
    a*=a;
    b>>=1;
  }
  return res;
}
void Chal_Ja_Plz(){
  int a, b, l;
  cin>>a>>b>>l;
  int X=log(l)/log(a);
  int Y=log(l)/log(b);
  set<int>st;
  for(int x=0;x<=X+1;x++){
    for(int y=0;y<=Y+1;y++){
      int p=power(a,x);    
      int q=power(b,y)      ;
      if(l%(p*q)==0){
        st.insert(l/(p*q));
      }
    }
  } 
  cout<<st.size()<<endl;
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