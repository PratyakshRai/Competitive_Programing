/*
Author: Pratyaksh Rai
Date: 2026-02-23
Time: 17:24:18
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
  vi arr(n),brr(n);
  invec(arr);
  invec(brr);
  bool flag=false;
  map<int,int>mp;
  for(int i=0;i<n;i++){
    int num=arr[i];
    int test=num+1;
    int j=2;
    while(j*j<=num){
      if(num%j==0){
        if(mp.find(j)==mp.end()){
          mp[j]++;
        }else {
          cout<<"0\n";return;
        }
      }
     
      while(num%j==0){
        num=num/j;
      }
      j++;
    }
    if(num>1){
      if(mp.find(num)!=mp.end()){
        cout<<"0\n";
        return;
      }
      else mp[num]++;
    }

  } 
  for(int i=0;i<n;i++){
    int test=arr[i]+1;
    int j=2;
    while(j*j<=test){
      if(test%j==0&&mp.find(j)!=mp.end()){
        cout<<"1\n";return;
      }
      while(test%j==0){test=test/j;}
      j++;
    }
    if(test>1)if(mp.find(test)!=mp.end()){
      cout<<"1\n";return;
    }
  }
  cout<<"2\n";return;
  
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