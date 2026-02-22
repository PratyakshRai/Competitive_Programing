/*
Author: Pratyaksh Rai
Date: 2026-02-02
Time: 22:28:37
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
      let x y be the adj pair , we can say first reduce the dublicate numbers , like 
      if you have  4 4 as an adjacent then 
      the minimum they can yeild is 4  so its better to reduce the consecutive duplicate  .then the new array formed will not have any consecutive duplicate

      
      , then try to combine the minimum vaules to each other but how ? 
      
*/
// Hints From Code 
/*  
CODE BY TEJA DRONADULA
*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   set<pair<int,int>>val;
   set<int>s;
   vi arr(n);
   for(int i=0;i<n;i++){
    int x ;cin>>x;
    val.insert({x,i});
    s.insert(i);
    arr[i]=x;
   }
   int ans=0;
   while(s.size()>1){
    auto pick=val.begin();
    int value=(*pick).ff;
    int idx=(*pick).ss;
    val.erase(pick);
    auto g=s.lower_bound(idx);
    int l , r;
    if(g!=s.begin()){
      g--;l=*g;
    }else l=*(--s.end());
    g=s.upper_bound(idx);
    if(g!=s.end())r=*g;
    else r=*(s.begin());
    ans+=min(arr[l],arr[r]);
  s.erase(idx); 
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