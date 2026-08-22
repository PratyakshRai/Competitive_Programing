/*
Author: Pratyaksh Rai
Date: 2026-03-29
Time: 13:44:50
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
There is always a simpler solution for the question 
*/
  int n;cin>>n;
  map<int,int>mp;
  int temp=n;
  for(int i=2;i*i<=n;i++){
   
    while(temp%i==0){
       if(temp%i==0)mp[i]++;
      temp=temp/i;
    }

  } 
  if(temp>1)mp[temp]++;
  // for(auto it :mp)cout<<it.ff<<" "<<it.ss<<"  ";
  // cout<<endl;

  if(mp.size()==1){
    auto it =mp.begin();
    int no=it->ff;
    int freq=it->ss;
    if(freq<6){
      NO;return;
    }
    YES;
    cout<<no<<" "<<no*no<<" "<<n/(no*no*no)<<endl;
    return;
  }
  if(mp.size()==2){
    auto it =mp.begin();
    int firstno=it->ff;
    int firstfreq=it->ss;
    mp.erase(firstno);
    it =mp.begin();
    int secondno=it->ff;
    int secondfreq=it->ss;
    if(firstfreq+secondfreq<4){
      NO;return;
    }
    YES;
    if(firstfreq==2&&secondfreq==2){
      cout<<firstno<<" "<<secondno<<" "<<firstno*secondno<<endl;
      return;
    }
    if(firstfreq>=secondfreq){
      cout<<firstno<<" "<<firstno*firstno<<" "<<n/(firstno*firstno*firstno)<<endl;
      return;
    }
    if(secondfreq>firstfreq){
      cout<<secondno<<" "<<secondno*secondno<<' '<<n/(secondno*secondno*secondno)<<endl;
      return;
    }
  }
  YES;
  auto first=mp.begin();
  int val1=first->ff;
  mp.erase(first);
  first=mp.begin();
  int val2=first->ff;
  cout<<val1<<" "<<val2<<" "<<n/(val1*val2)<<endl;


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