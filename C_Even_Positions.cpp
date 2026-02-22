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
we have to make a valid RBs and also to minimize the cost 
*/

// Small Observatins
/*

*/
//Your attacks
/*
we will make two different positions for  "(" and ")"
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
  int n;cin>>n;
  string s; cin>>s;
  int cnt=0;
  for(int i=0;i<n;i++){
    if(s[i]=='(')cnt++;
    else if (s[i]==')')cnt--;
    else {
      if(cnt>0){s[i]=')';cnt--;}
      else {
        s[i]='(';
        cnt++;
      }
    }
  }
  set<int>st;
  int ans=0;
  for(int i =0 ;i<n;i++){
    if(s[i]=='(')st.insert(i);
    else {
      int temp=*st.rbegin();
      ans+=i-temp;
      st.erase(temp);
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