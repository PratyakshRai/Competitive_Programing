/*
Author: Pratyaksh Rai
Date: 2026-03-23
Time: 18:30:25
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

      you are given an array , in short you can suffle the digits , such that the generated array c is the maximum possible 
      where  ci is gcd(b1, b2, .. , bi );

      hence give that suffled array 


  
*/

// Small Observatins
/*

*/
//Your attacks
/*

      i have to make ci large as possible   , 

      for that , 

      i will choose bi and for bi , bi+1 should be the divisor for bi  ,  

      and for that bi should be large as possible  


      and we will use the largest number first , wheather it has divisors or not , 
      
      let if it has no divisors , then , 

      the number afterwards in ci will be 1 , and hence any combination is good 

      now the problem breaks into 

      how to store a number and its divisors from the given array list 

      now see the n , it is 10^3 
      so we can do n^2 

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n ;cin>>n; 
   vi a(n);
   invec(a);
  //  sort(all(a));
  //  reverse(all(a));
   vi ans;
   vector<bool>visited(n,false);
   int d=0;
   for(int i=0;i<n;i++){
    int ind=0;
    int maxi=0;
    for(int j=0;j<n;j++){
      if(!visited[j]&&gcd(d,a[j])>maxi){
        maxi=gcd(a[j],d);
        ind =j;
      }
    }
    d=maxi;
    visited[ind]=true;
    ans.pb(a[ind]);
   }
   for(auto it : ans)cout<<it<<" ";
   cout<<endl;
  //  int currgcd=a[0];
  //  for(int i=1;i<n;i++)
  //  {
  //   int idx=i;
  //   int tempgcd=gcd(currgcd,a[i]);
  //   for(int j=0;j<n;j++){
  //     if(!visited[j]){
       
  //     if(tempgcd<gcd(currgcd,a[j])){
  //       tempgcd=gcd(currgcd,a[j]);
  //       idx=j;
  //     }}
  //   }
  //   visited[idx]=true;
  //   ans.pb(a[idx]);

  //  }
  //   for(auto it :ans)cout<<it<<" ";
  //   cout<<endl;

  //  map<int,vector<int>>mp;
   
  //  for(int i=n-1;i>=0;i--)
  //  {
    
  //   if(!visited[i]){
  //     visited[i]=true;
  //     mp[a[i]].pb(a[i]);
  //     if(a[i]==1)continue;
  //     for(int j=i-1;j>=0;j--){
  //       if(a[i]%a[j]==0){
  //       if(!visited[j]){
  //         visited[j]=true;
  //         mp[a[i]].pb(a[j]);
  //       }}
  //     }
  //   }

  //  }
  //  vector<vector<int>>ans;
  //  for(auto it : mp ){
  //   vector<int>temp;
  //   for(int i=0;i<it.ss.size();i++){
  //     temp.pb(it.ss[i]);
  //   }
   
  //   ans.pb(temp);

  //  }
  //  sort(all(ans));
  //  reverse(all(ans));
  //  for(int i=0;i<ans.size();i++){
  //   for(int j=0;j<ans[i].size();j++){
  //     cout<<ans[i][j]<<" ";
  //   }
  //  }
  //  cout<<endl;;
  //  for(auto it :mp){
  //   cout<<it.ff<<"  ";
  //   cout<<endl;
  //   for(int i=0;i<it.ss.size();i++){
  //     cout<<it.ss[i]<<" ";
  //   }
  //   cout<<endl;;
  //  }
  //  for(auto it =mp.rbegin();it!=mp.rend();it++){
  //   for(int i =it->second.size()-1;i>=0;i--){
  //      cout<<it->second[i]<<" ";
  //   }
  //  }
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