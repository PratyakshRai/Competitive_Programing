/*
Author: Pratyaksh Rai
Date: 2026-03-28
Time: 20:24:45
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

  hame number of ways to partition subarray chahiye ? 


  so agar x ya y  me se koi ek zero hua ? 
  to get the number of divisors 
  but agar dono hi zero nhi hue to ? 
  then find the combine no of divisors 
  except 1 



  x-y ko na karna tha ? 
  if x==y hai to ? 
  partition ek hi banega ? 


*/

// Small Observatins
/*

*/
//Your attacks
/*
min sum ek liye alt sum kar sakte hai ? rigth ? 

*/
// Hints From Code 
/*  

*/
int countdiv(int n ){
  int cnt=0;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      cnt++;
      if(n%(n/i)==0&&(i!=(n/i)))cnt++;
    }
  }
  return cnt;
}
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
   int x,y;cin>>x>>y;
   int tot=abs(x-y);
   int d=countdiv(tot);
   if(tot==0){
    cout<<1<<endl;;
   }
   else {
    cout<<d%676767677<<endl;

   }
   for(int i=0;i<x;i++)cout<<1<<" ";
   for(int i=0;i<y;i++)cout<<-1<<" ";
   cout<<endl;;
  //  if(x>0&&y>0){
  //   cout<<d-1<<endl;;
  //   for(int i=0;i<min(x,y);i++)cout<<"1 -1 ";
  //   for(int i=0;i<x-min(x,y);i++)cout<<1<<' ';
  //   for(int i=0;i<y-min(x,y);i++)cout<<-1<<" ";
  //   cout<<endl;
  //   return;
  //  }
  //  cout<<d<<endl;
  //  int f;
  //  if(x==0)f=-1;
  //  if(y==0)f=1;
  //  for(int i=0;i<tot;i++)cout<<f<<" ";
  //  cout<<endl;
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