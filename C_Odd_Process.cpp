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
odd +even =odd 
pahale odd wale ko dalenge phir even 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
  vi e , o; 
  int sum = 0 ;
  for( int i = 0 ; i < n ; i++ ){
    int temp ; cin>>temp;sum +=temp; 
    if(temp&1){
      o.pb(temp);
    }
    else {
    e.pb(temp);}
  }
  sort(all(o));
  sort(all(e));
  if(e.size()==n){
    for(int i = 0 ;i < n ;i++){
      cout<<"0 ";
    }
    cout<<endl;
    return;
  }
  if(o.size()==n){
    for(int i = 0 ; i < n  ; i++){
      if(i%2==0){
        cout<<o.back()<<" ";
     
      }else {
        cout<<"0 ";
      }
    }
    cout<<endl;
    return;
  }
  vi ans(n);
  ans[0]=o.back();
  o.pop_back();
  for(int i = 1 ; i < n ; i++){
    if(e.size()==0){
      ans[i]=ans[i-2];
    }else {
      ans[i]=ans[i-1]+e.back();
      e.pop_back();
    }
  }
  if(sum%2==0){
    ans[n-1]=0;
  }
  for(int i :ans)cout<<i<<" ";
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