/*
Author: Pratyaksh Rai
Date: 2026-01-21
Time: 15:15:19
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
      we have to think greedly :)

          claim: 
          pick n , sort the array , 
          check the difference 
          add it to the array, increase the counter 



          the difference should be greater than 1 , 
          the diff should not be equal to the prev



*/
// Hints From Code 
/*  
          suru se hi fixed kardiya , ye galti hui hai :
          ye jaruri nhi ki ek point per hi ham prev=n; kre , 
          yeh bhi ho sakta hai ki peeche ke kuch points na lene ki wajah se sam aage ke points le payein

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   int prev=n;
   int cnt=1;
  sort(all(arr));
  int ans=0;
  int left=0;
 
  arr.erase(unique(all(arr)), arr.end());
   int t=arr.size();
  for(int i=1;i<t;i++){
   while(arr[i]-arr[left]>=n)left++;
   ans=max(ans,i-left+1);
  }

   cout<<max(1LL,ans)<<"\n";
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