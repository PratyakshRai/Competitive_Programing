/*
Author: Pratyaksh Rai
Date: 2026-04-01
Time: 22:23:57
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

    n bases in a line , with the kth of which being the home base for your army

    initially there is only one single sodier at base k 
   
    har din ek nya banda aa rha hai kth base par  , 
    hame maximum no of fortified base chahiye on mth base 

    fortified matlab atleast one soldier hone chahiye 


    i have to focus on distribution of soldiers 

    how to utilize the maximum no of soldiers , like how to make them put into 
    max distances 




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
/*
There is always a simpler solution for the question 
*/
   int n,m,k;cin>>n>>m>>k;
   int l=1,h=n;
   k--;
   while(l<h){
    int mid=(l+h+1)/2;
    int an=LLONG_MAX;
    for(int L=0, R=mid-1;R<n;L++,R++){
      if(k<L)break;
      if(k>R)continue;
      int left=k-L;
      int right=R-k;
      an=min(an,left-1LL+max(left,right)+right);

    }
    if(an<=m)l=mid;
    else h=mid-1;
   }
   cout<<l<<endl;;
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