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
kisi ek row aur col ko pakdenge aur dekhenge ki saare usse bde ya saare usse chhote hai ki nhi 
 
  aga dono hi condition galat ho gye ho phi

      no 
      else yes 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n , m ;cin>>n>>m;
   vector<string>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
 if(arr[0][0]==arr[n-1][m-1]){
  YES;return;
 }
 else if (arr[0][m-1]==arr[n-1][0]){
  YES;return;
 }
 bool f1=false;
 if(arr[0][0]==arr[0][m-1]){
  for(int j=0;j<m;j++){
    if(arr[n-1][j]==arr[0][0]){
      YES;
      return;
    }
  }
 }if(arr[n-1][0]==arr[n-1][m-1]){
  for(int j=0;j<m;j++){
    if(arr[0][j]==arr[n-1][0]){
      YES;
      return;
    }
  }
 }
 
 if(arr[0][0]==arr[n-1][0]){
  for(int j=0;j<n;j++){
    if(arr[j][m-1]==arr[0][0]){
      YES;
      return;
    }
  }
 }if(arr[0][m-1]==arr[n-1][m-1]){
  for(int j=0;j<n;j++){
    if(arr[j][0]==arr[n-1][m-1]){
      YES;
      return;
    }
  }
 }
NO;


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

*/ //  set<int>rt,ct;
  //  for(int i =0;i<n;i++){
  //   bool flag =true;
  //   for(int j=0;j<m;j++){
  //     if(arr[i][j]=='B'){
  //       flag=false;
  //       break;
  //     }
  //   }
  //   if(flag)rt.insert(i);
  //  }
  //  for(int i =0;i<m;i++){
  //   bool flag =true;
  //   for(int j=0;j<n;j++){
  //     if(arr[j][i]=='B'){
  //       flag=false;
  //       break;
  //     }
  //   }
  //   if(flag)ct.insert(i);
  //  }
  //  bool ans=false;
  //  ans|=(rt.find(0)!=rt.end());
  //  ans|=(rt.find(n-1)!=rt.end());
  //  ans|=(ct.find(m-1)!=ct.end());
  //  ans|=(ct.find(0)!=ct.end());
  // if(ans)NO;
  // else YES;
  // bool ans =false;
  // pair<char,int>p;
  // p={'B',0};
  // for(int i =0;i<n;i++){

  //   for(int j=0;j<m;j++){
  //     if(p.ff==arr[i][j])p={'B',i*m+j};
  //   }
  // }
  // if(p.ss==n*m-1)ans=true;
 
  // p={'W',0};
  // for(int i =0;i<n;i++){

  //   for(int j=0;j<m;j++){
  //     if(p.ff==arr[i][j])p={'W',i*m+j};
  //   }
  // }
  // if(p.ss==n*m-1)ans=true;
  // if(ans)YES;
  // else NO;
  //  bool ch1=false,ch2=false;
  //   for(int i =0;i<n;i++){
  //     if(arr[i][0]==arr[i][m-1]){
  //       if(arr[i][0]=='B')ch1=true;
  //       else ch2=true;
        
  //     }
  //   }
  //    for(int i =0;i<n;i++){
  //   bool flag1 =false, flag2=false;
  //   for(int j=0;j<m;j++){
  //     if(arr[i][j]=='B')flag1=true;
  //     else flag2=true;
  //     }
  //     ch1&=flag1;
  //     ch2&=flag2;
  //   }
  //   if(ch1||ch2)YES;
  //   else NO ;