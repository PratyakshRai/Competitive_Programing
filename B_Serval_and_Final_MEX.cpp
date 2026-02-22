/*
Author: Pratyaksh Rai
Date: 2026-01-20
Time: 20:30:07
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
            hame mex ko zero bnana hai  so jo akhiri l  aur  r  choose kar rhe hai usme zero nhi hona chahiye 
            last ke 4 no se hi faisala ho jayega x 0 0 0 rha to 1 2 , 2 3 , 1 2
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   int cnt=0;
   vector<pair<int,int>>ans;
   for(int i=0;i<n;){
    if(arr[i]==0){
        if(i!=n-1)
        ans.pb({i-cnt+1,i+1-cnt+1});
        else ans.pb({i-1-cnt+1,i-cnt+1});
        i+=2;
        cnt++;
    }else i++;
   }
   ans.pb({1,n-cnt});
   cout<<ans.size()<<endl;
   for(auto i:ans){
    cout<<i.ff<<" "<<i.ss<<"\n";
   }

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