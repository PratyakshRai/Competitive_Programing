/*
Author: Pratyaksh Rai
Date: 2026-01-20
Time: 21:07:21
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
              agar  let k=2, to dono subarray ka mex M hai , so 
              we have a claim that ki overall mex bhi M hoga , 
              to ham overall mex nikal ke partition kar denge 



                  ab problem ye hai ki ham running me mex kaise nikale 
                  ek set bna sakte hai 




                  problem is than i have to include those who does not make any diffference in the mex 
                      what i can do is to check the last index and put it n , that's it 



                      edge case , if mex is zero , then we have to print  1 1 , 2 2 .....

*/
// Hints From Code 
/*  

*/
int mex(vector<int>&arr,int n){
  vector<int>seen(n+1);
  for(int i=0;i<n;i++)seen[arr[i]]++;
  for(int i=0;i<=n;i++){
    if(seen[i]==0)return i;
  }
  return n+1;
}
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   int mexx=mex(arr,n);
  //  cout<<mexx<<endl;
   if(mexx==0){
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
      cout<<i<<" "<<i<<"\n";
    }
    return;
   }
   set<int>st,temp;
   for(int i=0;i<mexx;i++)st.insert(i);
   vector<pair<int,int>>ans;
   temp=st;
   int prev=0;
  for(int i=0;i<n;i++){
    auto it =temp.find(arr[i]);
    if(it!=temp.end()){
      temp.erase(it);
    }
    if(temp.empty()){
      ans.pb({prev,i});
      temp=st;
      prev=i+1;
    }
   }
   if(ans.size()>1){
   cout<<ans.size()<<endl;
   int S=ans.size();
   for(int i=0;i<S-1;i++){
    cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<"\n";
   }
   cout<<ans[S-1].ff+1<<" "<<n<<"\n";
}
else cout<<"-1\n";
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