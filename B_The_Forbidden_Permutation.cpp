/*
Author: Pratyaksh Rai
Date: 2026-03-30
Time: 13:04:02
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

    p n 
    a m 
    d



*/

// Small Observatins
/*

  pos(ai)<pos(ai+1)
  pos(ai+1)<=pos(ai)+d

  iska matlab hai ai , aur ai+1 me atleast d distance ka gap 
  hona chahiye ? 


  it makes array not good  , hame good bnana hai 

  uske liye 

  ya to swap karke unka distance d is bda kardo if posible 
  or 
  swap karke ai>ai+1 kardo 

  but the thing is , ek ke swap karne se kya dusare par effect padega ? 



*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
int n,m,d;cin>>n>>m>>d;
vi a(n);
invec(a);
vi b(m);
invec(b);
vi pos(n+2);
for(int i=0;i<n;i++){
  pos[a[i]]=i+1;
}
int ans=1e9;
for(int i=0;i<m-1;i++){
  if(pos[b[i]]>=pos[b[i+1]]||pos[b[i+1]]>pos[b[i]]+d){
    cout<<0<<endl;return;
  }
  int beech=pos[b[i+1]]-pos[b[i]];
  ans=min(ans,beech);
  int temp=d;
  int right=n-pos[b[i+1]];
  int left=pos[b[i]]-1;
  if(right+left>=d-beech+1){
    ans=min(d-beech+1,ans);
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