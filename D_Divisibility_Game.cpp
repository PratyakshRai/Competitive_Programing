/*
Author: Pratyaksh Rai
Date: 2026-02-26
Time: 14:27:06
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

        alice = a, n 
        bob = b ,m 

        alice first 

        x is from a 
        y is from b 

        for alice y is divisible by x
        and 
            for bob y is not divisible by x 

        so y is always removed from the array b 
        
        no element from the array a is deleted 

        alice have to pick divisor of any element y in b from array a 

        bob have to pick non divisor of any element y in b from array a




*/
//Your attacks
/*

*/
// Hints From Code 
/*  
code by teja dronadula
*/
#define N 2000010
int reachable[N]={0};
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n ,m;cin>>n>>m;
int a[n],b[m];
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<m;i++)cin>>b[i];
int lc=1;
for(int i=0;i<n;i++){
  lc=lcm(lc,a[i]);
  if(lc>m+n)break;
}
set<int>s;
for(int i:a)s.insert(i);
for(int x:s){
  for(int y=x;y<=n+m;y+=x)reachable[y]=1;
}
int A=0,B=0,C=0;
for(int i=0;i<m;i++){
  if(reachable[b[i]]&&b[i]%lc==0)A++;
  else if (!reachable[b[i]]&&b[i]%lc!=0)B++;
  else C++;
}
if(C%2==0){
  cout<<(A>B?"Alice":"Bob");
}
else {
  cout<<(B>A?"Bob":"Alice");

}
cout<<endl;
for(int x:s){
  for(int y=x;y<=(n+m);y+=x)reachable[y]=0;
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