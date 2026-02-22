/*
Author: Pratyaksh Rai
Date: 2026-02-08
Time: 15:38:13
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
idea by teja dronadula
*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach

*/
   int n,k;cin>>n>>k;
   string s[k];
   
   for(int i=0;i<k;i++)cin>>s[i];
   vi div;
   for(int i=1;i*i<=n;i++){
    if(n%i==0){
        div.pb(i);
        if(n/i!=i)div.pb(n/i);
    }
   }
   sort(all(div));
   for(int di:div){
    int failed=0;
    string ans;
    
    for(int r=0;r<di;r++){
        int freq[26]={0};
        for(int i=0;i<(n/di);i++){
            int idx=i*di+r;
        int exists[26]={0};
        for(int j=0;j<k;j++){
            exists[s[j][idx]-'a']=1;
        }
        for(int p=0;p<26;p++)freq[p]+=exists[p];

        }
        int ok=0;
        char pos;
        for(int i=0;i<26;i++){
            if(freq[i]>=n/di){
                ok=1;
                pos='a'+i;
            }
        }
        if(!ok)failed=1;
        ans.pb(pos);
    }
    if(!failed){
        for(int i=0;i<n/di;i++){
            cout<<ans;
        }
        cout<<endl;return;
    }
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