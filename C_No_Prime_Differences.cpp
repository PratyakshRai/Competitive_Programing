/*
Author: Pratyaksh Rai
Date: 2026-03-10
Time: 20:44:30
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

      we are given n.m

      we have to construce a matrix 
      with the elements 

      1 to n.m 

      so that for each element 
      the abs with neighbour is not a prime number 


      if for each cell we iterate through its neighbour 
      it will cost , 4*n*m 

      what are the primes we can get after 
      abs(a-b) ? 
        prime <= abs(1-m*n) 

      let n*m is 16 
      2 3 5 7 11 13 are the primes 

      what different must not be there ?
      
      abs(a-b)!= any of the primes 
      how should i achieve this ? 

      can i make the difference for the 
      rows and cols same 

*/

// Small Observatins
/*

*/
//Your attacks
/*

*/
// Hints From Code 
/*  
 code by editorial
*/
/*#include <bits/stdc++.h>
using namespace std;

int main() {

    int t; cin >> t;
    for(int tc = 1; tc <= t; ++tc) {

        int n, m; cin >> n >> m;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i % 2 == 0) cout << (n / 2 + i / 2) * m + j + 1 << ' ';
                else cout << (i / 2) * m + j + 1 << ' ';
            }
            cout << '\n';
        }
    }
}*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n,m;cin>>n>>m;
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(i%2==0)cout<<(n/2 +i/2)*m+j+1<<" ";
    else cout<<(i/2)*m+j+1<<" ";
  }
  cout<<endl;
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