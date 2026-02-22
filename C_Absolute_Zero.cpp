/*
Author: Pratyaksh Rai
Date: 2026-02-10
Time: 12:53:27
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
int median(vector<int>& a) {
    int n = a.size();
    if (n % 2 == 1)
        return a[n/2];
    else
        return (a[n/2 - 1] + a[n/2]) / 2;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n;cin>>n;
   set<int>st;
   for(int i=0;i<n;i++){
    int x;cin>>x;
    st.insert(x);
   }
   if(st.size()==1){
    if(*st.begin()!=0){
      cout<<1<<endl;
      cout<<*st.begin();

    }else cout<<"0";
    cout<<endl;
    return;
   }
   vi arr;
   for(auto it :st)arr.pb(it);
   vi ans;
   for(int i=0;i<=40;i++){
    if(st.size()==1&&*st.begin()==0)break;
    int t=median(arr);
    set<int>y;
    for(int i:st){
      y.insert(abs(i-t));
    }
    ans.pb(t);
    
   arr.clear();
    for(int i:y)arr.pb(i); st=y;
   }
   if(st.size()>1){
    cout<<"-1\n";return;
   }
   cout<<ans.size()<<endl;
   for(int i:ans)cout<<i<<" ";
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