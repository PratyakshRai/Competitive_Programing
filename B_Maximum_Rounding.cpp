/*
Author: Pratyaksh Rai
Date: 2026-01-18
Time: 23:11:25
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
    <5 rhe to kuchh karna sahi nhi hai , other wize ,  jha >=5 rhe waha bada denge number ko 
          ab problem 999 wale case me aa jati hai 
          to loop laga denge jaha tak 999 hai , uske baad waha tk ho jayega 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
  string s;cin>>s;
  s="0"+s;
  int n=s.size();
  for(int i=n-2;i>=0;i--){
    if(s[i+1]-'0'<5)continue;
  
    while(s[i]-'0'>=4){
      s[i]='0';
      i--;
    }
    int t=s[i]-'0';
    t++;
    s[i]=t+'0';
      s.erase(s.end()-(n-1-i),s.end());
    string ad=string(n-i-1,'0');
    s=s+ad;
    i++;
  }
  if(s[0]=='0')s.erase(s.begin());
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