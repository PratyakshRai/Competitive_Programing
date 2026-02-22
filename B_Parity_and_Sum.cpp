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
   int n;cin>>n;
   vector<int>even;
    int bigodd=0;
   for(int i = 0 ; i < n ; i ++){
    int temp;cin>>temp;
    if(temp&1){bigodd=max(bigodd,temp);}
    else even.pb(temp);
   }
   if(even.size()==0||even.size()==n){
  cout<<"0\n";
  return;
   }int ans1=0;
   int big=bigodd;
   sort(all(even));
   for(int i : even ){
    if(bigodd>i){ans1++;bigodd+=i;}
    else{ ans1+=2;bigodd+=2*i;}
    
   }
   int ans=0;
   reverse(all(even));
   for(int i : even ){
    if(big>i){ans++;big+=i;}
    else{ ans+=2;big+=2*i;}
    
   }
   cout<<min(ans,ans1)<<endl;
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