/*
Author: Pratyaksh Rai
Date: 2026-01-10
Time: 20:20:50
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

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   string s2 , s1 ;cin>>s2>>s1;
   vector<int>OG,h;
   string t1="";
   string t2="";
   int cnt=0;
   char ch='#';
  for(char c: s2){
    if(ch=='#'){
        ch=c;
        cnt=1;
    }else if(ch == c){
            cnt++;
        } else {
            t1+=ch;
            OG.pb(cnt);
            ch = c;
            cnt = 1;
        }
  }
  t1+=ch;

OG.pb(cnt); 
cnt=0;
ch='#';
for(char c: s1){
    if(ch=='#'){
        ch=c;
        cnt=1;
    }else if(ch == c){
            cnt++;
        } else {
            t2+=ch;
            h.pb(cnt);
            ch = c;
            cnt = 1;
        }
  }



h.pb(cnt);
t2+=ch;
bool flag=(t1==t2);
// cout<<t1<<" "<<t2<<endl;
if(flag==false){
    NO;
    return;
}
 int t=h.size();
 for(int i=0;i<t;i++){
    int mn=OG[i];
    int mx=OG[i]*2;
    if(h[i]<mn||h[i]>mx){
        NO;
        return;
    }
 }  
 YES;
 

// cout<<t<<endl;
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