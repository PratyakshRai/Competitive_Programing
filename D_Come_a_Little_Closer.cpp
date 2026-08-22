/*
Author: Pratyaksh Rai
Date: 2026-02-24
Time: 21:17:43
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

    a large no of cells 10^9 !! 


          n monters at ( xi , yi ) so multiple in same cell 

          i have to make all the elements closer 
          

          just see the breath col(maxj -mini +1)
                       lenght row(maxi-mini +1)
              
            can we reduce the length or breath

















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

   vector<pair<int,int>>p;
   multiset<int>X,Y;
   for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    p.pb({x,y});X.insert(x);Y.insert(y);
   }
   if(n==1){
    cout<<1<<endl;return;
   }
   int ans=(*X.rbegin()-(*X.begin())+1)*(*Y.rbegin()-(*Y.begin())+1);
   
   for(int i=0;i<n;i++){
    int x=p[i].ff;
    int y=p[i].ss;
    auto xt=X.find(x);
    auto yt=Y.find(y);
    X.erase(xt);
    Y.erase(yt);
    int total =(*X.rbegin()-(*X.begin())+1)*(*Y.rbegin()-(*Y.begin())+1);
    if(total>n-1){
      ans=min(ans,total);
    }else {
      ans=min(ans,total+min((*X.rbegin()-(*X.begin())+1),(*Y.rbegin()-(*Y.begin())+1)));
    }
    X.insert(x);
    Y.insert(y);
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