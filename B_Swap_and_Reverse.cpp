/*
Author: Pratyaksh Rai
Date: 2026-01-18
Time: 11:30:59
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
si aur si+2 hai , iska matlab ham odd aur even position par sorting karsakte hai 
      ab reverse ka kaise use karein ? 
      agar k==2 hua tb to pure sort kardenge 
          if k>2 ? otherwise smallest nhi de sakta hai?
          agar k even hai to reverse karte time ever odd ka order badal jayega , to do baar reverse kar denge aur phir operation one laga denge , jisse adj. swap ho jayeinge
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n, k;cin>>n>>k;
   string s ;cin>>s;
   if(k%2==0){
    sort(all(s));
    cout<<s<<endl;
    return;
   }
   vector<char>even,odd;
   for(int i=0;i<n;i++){
    if(i%2==0)even.pb(s[i]);
    else odd.pb(s[i]);
   }
   sort(all(odd));
   int a=0,b=0;
   sort(all(even ));
   for(int i=0;i<n;i++){
    if(i%2==0){
      cout<<even[a];
      a++;
    }
    else cout<<odd[b++];
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