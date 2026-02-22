/*
Author: Pratyaksh Rai
Date: 2026-02-04
Time: 19:38:29
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
    match sirf ek baar hi hoga , like pahale alice and then bob thats it 

        no of ways alice can win regardless of bob actions? 
        it should be strictly greater than thing

        i thing bob will play optimally as in the test case 1 1 2 4 , alice wins is  0 

        if bob plays optimally , then when will he win ? 

        when he chooses largest element either it is already choosen by red or not 

        first calculate the total permutation 
        then after 
            you have to find that triplet whoes sum is <= the largest
            use three sum technique  with modification
*/
// Hints From Code 
/*  
Code by editorial
*/

void Chal_Ja_Plz(){
   int n;cin>>n;
   vi arr(n);
   int freq=0;
   invec(arr);
   int ans=0;
   int mx=*max_element(all(arr));
   for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      int test=max(2*arr[i],arr[n-1])-arr[i]-arr[j];
      int k=upper_bound(arr.begin(),arr.begin()+j,test)-arr.begin();
      ans+=j-k;
    }
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