/*
Author: Pratyaksh Rai
Date: 2026-02-13
Time: 14:34:53
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
make visited array 



      iterate dfs but check the max eleement like if you got the max element stop there or save the values for k , 
*/
// Hints From Code 
/*  

*/
int cal(vector<int>& p, vector<int>& arr, int n, int start, int k) {
    vector<int> visited(n, 0);

    int idx = start;
    long long prefix = 0;
    long long ans = 0;

    while (!visited[idx] && k > 0) {
        visited[idx] = 1;

        prefix += arr[idx];
        k--;
        ans = max(ans, prefix + k * arr[idx]);

        idx = p[idx];
    }

    return ans;
}

void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,k,B,S;cin>>n>>k>>B>>S;B--;S--;
   vi p(n);
   for(int i=0;i<n;i++){
    int x;cin>>x;x--;

    p[i]=x;
   }
   vi arr(n);
   invec(arr);
   int bo=cal(p, arr,n,B,k);
   int sa=cal(p,arr,n,S,k);
   if(bo>sa){
    cout<<"Bodya\n";
   }else if (bo<sa){
    cout<<"Sasha\n";
   }else cout<<"Draw\n";

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