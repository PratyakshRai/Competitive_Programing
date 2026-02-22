/*
Author: Pratyaksh Rai
Date: 2026-01-26
Time: 19:04:38
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
        so we can compare , like for a given k , where pi can go 
                if pi ==i , then do nothing 
                otherwise   
                          for pi at a index i 
                              check the index of pi+k and pi-k  
                              
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n,k;cin>>n>>k;
   vi arr(n);
   invec(arr);
   vi dup(n);
   for(int  i=0;i<n;i++){
    if(abs(arr[i]-i-1)%k==0){
      dup[arr[i]-1]=arr[i];
    }
   }
   int z=count(dup.begin(),dup.end(),0);
   if(z==0)cout<<"0";
   else if(z==2)cout<<"1";
   else cout<<"-1";
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