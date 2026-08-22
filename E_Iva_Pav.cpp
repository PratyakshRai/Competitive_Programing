/*
Author: Pratyaksh Rai
Date: 2026-03-07
Time: 23:07:40
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

        so we have an array of n elements 

        f(l,r) mean bitwise and operations of all the elements 
        between al ..ar (inclusively)

        l<=r might possible 

        we have to answer q querries (q<=10^5 )

        in which we were given 

        l and k , we have to find the largest r 
        such that f(l,r)>=k

        if no r posible , -1 should be there 


        we cant do n*r , 

        will making the prefix ands , helps ? 



        for a particular l  , how to find such r 
        without iterating for larger  values ? 




*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
int get_and(int l, int r , vector<vector<int>>&pref){
  int res=0;
  int len=r-l+1;
  for(int j=0;j<30;j++){
    int count =pref[r][j]-pref[l-1][j];
    if(count==len){
      res|=(1LL<<j);
    }
  }
  return res;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n;cin>>n;
vector<int>a(n+1);
vector<vector<int>>pref(n+1,vector<int>(30,0));
for(int i=1;i<=n;i++){
  cin>>a[i];
  for(int j=0;j<30;j++){
    pref[i][j]=pref[i-1][j]+((a[i]>>j)&1);
  }
}
int q ;cin>>q;
while(q--){
  int l, k;cin>>l>>k;
  if(a[l]<k){
    cout<<"-1 ";
    continue;
  }
  int low=l,high=n,ans=l;
  while(low<=high){
    int mid=(low+high)/2;
    if(get_and(l,mid,pref)>=k){
      ans=mid;
      low=mid+1;
    }
    else {
      high=mid-1;
    }
    
  }
  cout<<ans<<" ";
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