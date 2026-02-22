/*
Author: Pratyaksh Rai
Date: 2026-02-03
Time: 23:02:03
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


// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Problem Statement
/*
            write the ralation , like what does it wants 


            all are in the powers of two , so no need to calculate the powers , just compare the highest power like a boss 

            the thing is it is a permutation , so no further repetition of digits in the array 


            what is the problem ? 

            how to find the maximum in less than TC(n)
            something like log n or less? 

            yes it can , 
            for each iteration calculate the maximum in both the array with their idx , compare the maximum , if mx1>mx2 strictly , then it is easy , otherwise we have to check the othervalue of the pair also by i-idxof(max(mx1 ,mx2));
            
            then we got who is the boss of that iteration i , then just store theie index for future fast modulo power trick 

*/
int binaryexporecursive(int a , int b){
    if(b==0)return 1;
    int half=binaryexporecursive(a,b/2);
    half=half*half;
    if(b&1)return half*a;
    return half;
}
int binaryexpoiterative(int a , int b){
    int res=1;
    while(b>0){if(b&1)res*=a;
        a=a*a;
        
        b>>=1;
    }return res;
}



// Small Observatins
/*

*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
// fast modulo power code by chatgpt 
const long long MOD = 998244353;

long long pow2(long long x) {
    long long res = 1;
    long long base = 2;

    while (x > 0) {
        if (x & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        x >>= 1;
    }
    return res;
}
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>a(n),b(n);
   invec(a);
   invec(b);
   vector<pair<int,int>>powrs;
   int mx1=-1,mx2=-1,idx1=-1,idx2=-1;
   for(int i=0;i<n;i++){
    if(mx1<a[i]){
        mx1=a[i];
        idx1=i;
    }
    if(mx2<b[i]){
        mx2=b[i];
        idx2=i;
    }
    if(mx1>mx2){
        powrs.pb({idx1,i-idx1});
    }else if(mx1<mx2){
        powrs.pb({i-idx2,idx2});

    }else {
         if(a[i-idx2]>b[i-idx1]){
              powrs.pb({i-idx2,idx2}) ;
        }else powrs.pb({idx1,i-idx1});
    }
    // else {
    //     if(a[i-idx1]>b[i-idx2]){
    //          powrs.pb({i-idx2,idx2}) ;
    //     }else powrs.pb({idx1,i-idx1});
    // }
   }
//    int t=0;
  vector<int>ans;
  for(auto i: powrs){
    int fi=a[i.ff];
    int si=b[i.ss];
    if(a[i.ff]==b[i.ff]){
        si=max(b[i.ss],a[i.ss]);
    }
   ans.pb((pow2(fi) + pow2(si)) % MOD);

  }
  for(int i:ans)cout<<i<<" ";
// for(auto it :powrs)cout<<it.ff<<it.ss<<" ";
cout<<endl;
}
//  3 5 8 
// 17 18 20 24 32 
// 544 768 1024 544 514 513 513 640 514 768 

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