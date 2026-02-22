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

*/
// Hints From Code 
/*  

*/
 
void Chal_Ja_Plz(){
   int n;cin>>n ;
   string s ; cin>>s; 
   map<char, int >mp; 
   for (int i = 0 ; i < n ; i++){
    if(mp.find(s[i])!=mp.end()){
      mp[s[i]]++;
    }else {
      mp[s[i]]=1;
    }
   }
   vector<pair<int,char>>arr;
   for(auto it :mp){
    arr.pb({it.ss,it.ff});
   }
   sort(all(arr));
   int j=0;
   for(int i = 0 ; i < n ; i++){
    cout<<arr[(j%arr.size())].ss;
    arr[(j%arr.size())].ff--;
    if(arr[(j%arr.size())].ff==0){
      arr.erase(arr.begin()+(j%arr.size()));
    }
    j++;
   }
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