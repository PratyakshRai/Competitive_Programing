/*
Author: Pratyaksh Rai
Date: 2026-01-17
Time: 17:50:45
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
manhattan distance hai lol , 
        do points ke beech me ek aur points hai 
        agar uska kharcha aa rha hai to minimum manhattan direct distance hoga , otherwise a se ek premium city me ghus  jao , aur jaha marji waha travel karo 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n, k,a,b;cin>>n>>k>>a>>b;
   a--;b--;
   vector<pair<int,int>>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i].ff>>arr[i].ss;
   }
   int d1=abs(arr[a].ff-arr[b].ff)+abs(arr[a].ss-arr[b].ss);
   set<int>A,B;
    for(int i=0;i<k;i++){
    A.insert(abs(arr[a].ff-arr[i].ff)+abs(arr[a].ss-arr[i].ss));
   }
   for(int i=0;i<k;i++){
    B.insert(abs(arr[b].ff-arr[i].ff)+abs(arr[b].ss-arr[i].ss));
   }
   int d2=*A.begin()+*B.begin();
   if(!A.empty()){
   cout<<min(d1,d2)<<endl;}
   else cout<<d1<<endl;
   
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