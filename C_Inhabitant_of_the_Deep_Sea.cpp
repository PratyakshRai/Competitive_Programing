/*
Author: Pratyaksh Rai
Date: 2026-02-13
Time: 20:56:10
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

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n, k ; cin>>n>>k;
   vi arr(n);
   invec(arr);
   int sum=accumulate(arr.begin(),arr.end(),0LL);
   if (sum<k){
    cout<<n<<endl;
    return;
   }
   int cnt=0;
   int left=0, right=n-1;
   while(left<right&&k>0){
    int l=(k+1)/2;
    int r=k/2;
    int mn1=0;
   if(l!=0&&r!=0){
    mn1=min(l,r);
   }else if(l==0)mn1=r;
   else mn1=l ;
    int L=arr[left],R=arr[right];
    // int mn1=min(l,r);
    // int mn2=min(L,R);
    int mn=min({mn1,L,R});
    if(l>=mn)
    arr[left]-=mn;
    if(r>=mn)
    arr[right]-=mn;
    k-=mn;
    k-=mn;
    // l-=mn;
    // r-=mn;
    if(arr[left]==0){
      cnt++;left++;

    }if(arr[right]==0){
      cnt++;right--;
    }
    // if((l+r)<=0){
    //   break;
    // }
    // k=k-2*mn;
   }
   if(left==right&&arr[left]<=k){
cnt++;
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