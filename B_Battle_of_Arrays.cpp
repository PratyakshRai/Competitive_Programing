/*
Author: Pratyaksh Rai
Date: 2026-04-02
Time: 15:31:47
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

        there is an array a of n pos
        array b of m pos integer
        

        alice moves first 

        on a player's turn , they must choose one element x from their own array 
        and the maximal element y from their opponent's array 

        y<=x y is destroyed 

        y>x , y is descreased by x 

        samne wale ka hamesha maximum element target me aa rha hai 
        aur mera kuchh nhi jayega 

        agar mai hamesha apna sabse bda wala element uthau to ? 
        kyu ki mera koi ghata nhi ho rha , samne wale ka ghata hoga 
        aur kaun chhutiya bada element rakhne ke baad bhi chhote element ko bhejega 



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
/*
There is always a simpler solution for the question 
*/
int n,m;cin>>n>>m;
multiset<int>a,b;
for(int i=0;i<n;i++){
  int x;cin>>x;a.insert(x);
}
for(int i=0;i<m;i++){
  int x;cin>>x;b.insert(x);
}
int bit=1;
while(!a.empty()&&!b.empty()){
  bit^=1;
  if(bit==0){
    auto it =prev(a.end());
    int val1=*it;
    auto t=prev(b.end());
    int val2=*t;
    if(val1>=val2){
      b.erase(t);
    }
    else {
      b.erase(t);
      val2-=val1;
      b.insert(val2);
    }
  }
  else {
    auto it =prev(b.end());
    int val1=*it;
    auto t =prev(a.end());
    int val2=*t;
    a.erase(t);
    if(val1<val2){
      val2-=val1;
      a.insert(val2);
    }
  }
}
if(a.empty()){
  cout<<"Bob\n";
  return ;
}
if(b.empty()){
  cout<<"Alice\n";
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