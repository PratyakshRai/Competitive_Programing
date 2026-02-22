/*
Author: Pratyaksh Rai
Date: 2026-01-17
Time: 23:34:54
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
sabase pahale palindrome bnaneke liye minimum no of ones nikalunga 
    phir uska matlab give string s palindrome ban gayi , 
        then after maximum no of one calculate karunga , aur like kuchh beech me no of chhut bhi jayenge 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s;cin>>s;
   string ans=string(n+1,'0');
   int cnt=0;
  for(int i=0;i<n/2;i++){
    if(s[i]!=s[n-i-1]){cnt++;
    s[i]='#';}
  }
  bool flag=((n%2!=0)?true:false);
  ans[cnt]='1';
  ans[cnt+flag]='1';
  int t=0;
  for(int i=0;i<n/2;i++){
    if(s[i]!='#'){
      t++;
      int c=cnt+2*t;
      ans[c]='1';
      ans[c+flag]='1';
    }
  }
  cout<<ans<<endl;
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