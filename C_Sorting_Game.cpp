/*
Author: Pratyaksh Rai
Date: 2026-01-17
Time: 21:08:37
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
alice ko pahale round me hi game over karna padega 

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s;cin>>s;
   
  //  int zero =count(s.begin(),s.end(),'0');
  //  if(zero==0||zero==n){
  //   cout<<"Bob\n";return;
  //  }
  //  string og ="";
  //  bool flag=false;
  //  for(int i=0;i<n;i++){
  //   if(flag){
  //     og+=s[i];
  //   }else{
  //   if(s[i]=='1'){
  //     flag=true;
  //     og+=s[i];
  //   }}
  //  }
  //    flag=false;
  //    for(int i=(int)og.size()-1;i>=0;i--){
  //     if(og[i]=='1'&&(!flag)){
  //       og[i]='#';
  //     }else {
  //       if(og[i]=='0')
  //       flag=true;
  //     }
       
  //    }
    
  //    int cnt=0;
  //    int ok=false;
  //    int a, b;
  //    for(int i=0;i<n;i++){
  //     if(s[i]=='1'&&(!ok)){
  //       a=i+1;ok=true;
  //     }
  //     if(s[i]=='0'){
  //       b=i+1;
  //       break;
  //     }
  //    }
  //     for(int i =a;i<=b;i++){
  //     indices.pb(i);
  //    }
  //    for(int i=1;i<og.size();i++){
  //     if(og[i-1]=='1'&&og[i]=='0'){cnt++;
        
  //    }}
  //    int add=n-og.size();
  //    if(cnt%2==0){
  //     cout<<"Bob\n";
  //    }
  //    else {
  //     cout<<"Alice\n";
  //     cout<<indices.size()<<"\n";
  //     for(int i:indices)cout<<i<< " ";
  //     cout<<endl;
      

  //    }
  if(is_sorted(s.begin(),s.end())){
    cout<<"Bob\n";

  return;
  }
  int cnt=count(s.begin(),s.end(),'0');
  vi index;
  for(int i=0;i<n;i++){
    if(i<cnt)
    {
      if(s[i]=='1')index.pb(i+1);
    }
  
  else {
    if(s[i]=='0')index.pb(i+1);
  }
  }
  cout<<"Alice"<<"\n";
  cout<<index.size()<<"\n";
  for(int x: index)cout<<x<<" ";
  cout<<endl;
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