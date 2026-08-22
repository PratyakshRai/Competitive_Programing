/*
Author: Pratyaksh Rai
Date: 2026-02-24
Time: 17:04:18
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

        an array is given 

        k is given 

        for each value of  k like k=0 , 1, 2, 3, ..

        we have to find the number of possible 
        value of mex(a) after removing exactly k elements 

        like if i want to remove 1 element then what will be the different possible mex values ? 



        if we store the freq 
             
            like 1 0 0 1 2 
             
            has 0:2 
                1:2
                2:1
        what are the mex values poss? 
          0 , 1, 2 , 3
             
            for a particular k , how many diff mex val we can create ? 
            if i dont remove any value ? 
            always be the same value 

k=0 , 1(always)

             if i have to k=1 values 
             then  
             2 
             if k=2? 


             0:1
             1:1
             3:1
             4:1







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
   map<int,int>mp;
   for(int i=0;i<n;i++){
    int x;cin>>x;
    mp[x]++;
   }
   vector<pair<int,int>>range;
   int mex=-1;
   for(int i=0;i<=n;i++){
    if(i==mex+1){
      int left=mp[i];
      int right=n-(i);
      range.pb({left,right});
      if(mp[i])mex++;
    }
    else break;
   }
   vector<int>prefix(n+2);
   for(auto it :range){
    prefix[it.ff]++;
    prefix[it.ss+1]--;
   }
   for(int i=1;i<=n;i++){
    prefix[i]+=prefix[i-1];
   }
   for(int i=0;i<=n;i++)cout<<prefix[i]<<" ";
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