/*
Author: Pratyaksh Rai
Date: 2026-01-21
Time: 19:48:55
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
            masha try karrega ki jo bhi do no wo choose kre unka sum even ho , , like odd +odd or even +even , if not possible then nothing he can do 
                olya try karega ki jo bhi do no wo choose kre unka sum odd to taki  floor value  par 1 km mille 


            notice karne wali cheej ye hai ki either after masha or olya there will be a even no generated 
            odd use hoga 2 1 2 1 ke pair me , like pahale masha 2 odd choose karegi , bhi olya  , 1 odd aur masha wala no 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   int sum=0;
   int odd=0;
   vi ans;
   for(int i=0;i<n;i++){
    sum+=arr[i];
    int s=sum;
    if(arr[i]%2!=0) odd++;
    s-=odd/3;
    int t=odd%3;
    if(t==1)s--;
    ans.pb(s);
  }
  ans[0]=arr[0];
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