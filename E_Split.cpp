/*
Author: Pratyaksh Rai
Date: 2026-01-20
Time: 13:07:13
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
        k ke upar cheeje depend karti hai
        if the frequency of elements is not enough to make every element store even in all the multiset , then 0 should be the answer
                otherwise atleast n should be the answer 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   multiset<int>curr,prev;
   int cnt=0;
   map<int,int>mp;
   for(int i:arr){
    if(mp.find(i)==mp.end()){
        mp[i]=1;
    }else mp[i]++;
   }
   prev.insert(arr[0]);
   curr.insert(arr[0]);
   mp[arr[0]]--;
   for(int i=1;i<n;i++){
    curr.insert(arr[i]);
    // mp[arr[i]]--;
    // if(mp[arr[i]]==0)break;
    auto it =prev.find(arr[i]);
    if(it!=prev.end()){
        prev.erase(it);
    }
    if(prev.empty()){
        prev=curr;
        curr.clear();
        cnt++;
    }
   }
   cout<<cnt<<endl;
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