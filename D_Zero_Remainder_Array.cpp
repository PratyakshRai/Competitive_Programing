/*
Author: Pratyaksh Rai
Date: 2026-03-26
Time: 22:39:37
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

        you have an array   , and an interger x 

        initially x =0 

        during one move , u can do two operations

        ya to ai me x jodo ya to na jodo  
        end me x++ to karna hi hai 
        

        u can choose one i at most once 

        minimum no of moves ,such that each its element is divisible by k 





*/
//Your attacks
/*


    those who are divisible , unhe ham nhi chhedenge 

    and since we only can add something to aa element 
    we will find what is required more to get a number divisible by k 


    4 4 6 8 10 
    do same rha to kisi ek ho hi satisfy kar payega , phir agla wala same no , next k divisible required , ie 4+k pe shift kar denge indirectly we are finding end of z+k , the largest number  , 
    that will be our answer 

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
int n,k;cin>>n>>k;
vi a(n);
invec(a);
map<int,int>mp;
for(int i=0;i<n;i++){
  int val=a[i];
  if(val%k==0)continue;
  if(val<k){
    mp[k-val]++;
  }
  else mp[k-val%k]++;
}
int ans=0;
// for (auto it : mp)cout<<it.ff<<" "<<it.ss<<"   ";
// cout<<endl;
while(!mp.empty()){
  auto it =mp.begin();
  int key =it->first;
  int val=it->second;
  mp.erase(it);
  ans=key+1;
  if(val==1)continue;
  mp[key+k]+=val-1;
 
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