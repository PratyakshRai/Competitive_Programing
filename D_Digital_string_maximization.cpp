/*
Author: Pratyaksh Rai
Date: 2026-02-04
Time: 23:30:07
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
    ek particular position ke liye dekhenge ki +9 i tk kausa maximum aa rha hai usko choose kar lenge 
    tc 9n
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
string s ;cin>>s;
int n=s.size();
   for(int i=0;i<n;i++){
    int idx=i;char mx=s[i];
    for(int j=i+1;j<n&&j<i+10;j++){
      int diff=j-i;
      char temp=(char)s[j]-diff;
      if(temp<'0')continue;
      if(temp>mx){
        mx=temp;
        idx=j;
      }
    }
    
    while(idx>i)
   { swap(s[idx],s[idx-1]);
    idx--;}
    // s[idx]=mx;
    // swap(s[i],s[idx]);
     s[idx]=mx;
   }
  
  //  cout<<endl;
    cout<<s<<endl;
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