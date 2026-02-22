/*
Author: Pratyaksh Rai
Date: 2026-01-19
Time: 20:15:43
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
    ham total no of permutation pahale se calculate karle 
        phir question change ho jayega , like two numbers and we have to calculate ony A and B
        ab kyuki dono me digits same hai to 
        B max no of digits hoga , aur jaha position bhi match kar gayi waha ham A++ aur B--;
*/
// Hints From Code 
/*  

*/
vector<vector<int>>arr={{12,21},{123,132,213,231,312,321},{1234,1243,1324,1342,1423,1432,
2134,2143,2314,2341,2413,2431,3124, 3142, 3214, 3241, 3412, 3421,4123, 4132, 4213, 4231, 4312, 4321}};
void Chal_Ja_Plz(){
   string n;cin>>n;
   int j,k;cin>>j>>k;
   j--;k--;
   int N=n.size();
   string J=to_string(arr[N-2][j]);
   string K=to_string(arr[N-2][k]);
   int a=0,b=N;
   for(int i=0;i<N;i++){
    if(J[i]==K[i]){
      a++;b--;
    }
   }
   cout<<a<<"A"<<b<<"B"<<endl;

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