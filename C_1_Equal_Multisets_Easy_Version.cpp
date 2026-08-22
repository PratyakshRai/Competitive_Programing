/*
Author: Pratyaksh Rai
Date: 2026-03-28
Time: 20:56:58
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

    we are given anarray 
    a is permutation 

    and a parameter k 
    
    a array b is called cool if 

     the array [ai−k+1,ai−k+2,…,ai] is a rearrangement of [bi−k+1,bi−k+2,…,bi].

     ? what does this means ? 

     it is matching the subarray of length k  , right ? 


     so we have to check if 
     for each subarray , can we get an equal rearrangment of b ? 
     
     print YES/NO





*/

// Small Observatins
/*
B may or may not be permutation 

    each element is dependent with other 

*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz() {
    // There is always a simpler solution for the question 
  int n,k;cin>>n>>k;
  vi a(n),b(n);invec(a);invec(b);
  set<int>BB;
  for(int i=0;i<n;i++){
    if(b[i]!=-1&&BB.find(b[i])!=BB.end()){
        NO;return;
    }
    BB.insert(b[i]);}
 
  int cnt=0;
  multiset<int>A,B;
  int ty=0;
  for(int i=0;i<k;i++){
    if(a[i]!=b[i]&&b[i]!=-1)ty=i;
    if(a[i]==b[i])continue;
    if(b[i]==-1){cnt++;A.insert(a[i]);}
    else {
       
      A.insert(a[i]);
      B.insert(b[i]);
    }
  }
  cout<<ty<<" ";
  for(int it:A){
    if(B.count(it)==0){
      if(cnt==0){NO;return;}
      else cnt--;
    }else {
      auto t=B.find(it);
      B.erase(t);
    }

  }

  int r=0;
  for(int i=k;i<n;i++){
    bool flag1=false;
    bool flag2=false;
    bool flag3=false;
    if(a[i]==b[i]||b[i]==-1){
      flag1=true;
    }
    
    if(a[r]==b[r]||b[r]==-1){
      flag2=true;
    }
    if(flag1&&flag2){}
    else {
      
      NO;return;
    }
    r++;
  }
  if(ty&&r!=0){NO;}
  else 
  YES;
}
// void Chal_Ja_Plz(){
// /*
// There is always a simpler solution for the question 
// */
//    int n,k;cin>>n>>k;
//    vi a(n+1);
//    vi b(n+1);
//    for(int i=1;i<=n;i++)cin>>a[i];
//    for(int i=1;i<=n;i++)cin>>b[i];

   

//   //  set<int>aa,bb;
//   //  int cnt=0;
//   //  set<int>one;
//   //  for(int i=1;i<=k;i++){
//   //   aa.insert(a[i]);
//   //   if(b[i]==-1){cnt++;one.insert(i);}
//   //   else {
     
//   //     bb.insert(b[i]);}
//   //  }
//   //  int m=k+1;
//   // int i;

//   // int temp=cnt;
//   // for(int j=1;j<=k;j++){
//   //   if(bb.find(a[j])!=bb.end())continue;
//   //   if(temp==0){
     
//   //     NO;return;
//   //   }
//   //   temp--;
//   // }

//   // for(int i=1;i<=n-k;i++){
//   //   if(bb.find(a[i])==bb.end()){
//   //     if(cnt==0){
//   //       NO;return;
//   //     }
//   //     cnt--;
//   //       auto t=one.begin();int idx=*t;one.erase(t);
//   //       b[idx]=a[i];
       

//   //   }
//   //    if(b[i] == -1){
//   //       cnt--;
//   //       one.erase(i);
//   //   } else {
//   //       bb.erase(b[i]);
//   //   }
//   //    if(m<=n){
//   //     if(b[m]==-1){
//   //       cnt++;
//   //       one.insert(m);

//   //     }
//   //     else bb.insert(b[m]);
//   //    }
//   //   m++;
//   // }
//   //    for(i=n-k+1;i<=n;i++){
//   //   if(bb.find(a[i])!=bb.end())continue;
//   //   if(cnt==0){
//   //     NO;return;
//   //   }
//   //   cnt--;
    
//   //  }
//   //  YES;


// //    for( i=1;i<=n-k;i++){
// //     if(b[i]==-1){
// //       b[i]=a[i];
// //       one.erase(i);
// //       cnt--;
// //     }
// //     else if (b[i]!=a[i]){
// //       NO;return;
// //     }else bb.erase(b[i]);
// //     // cnt--;
// //     // auto t=one.begin();int idx=*t;one.erase(t);
// //     // b[idx]=a[i];
// //     // bb.erase(b[i]);
// //     if(m<=n){
// //       if(b[m]==-1){
// //         cnt++;
// //         one.insert(m);
// //       }
// //       else{
// //         if(b[m]!=a[m]){
// //           NO;return;
// //         }
// //         if(bb.count(b[m])){
// //         NO;return;
// //       }bb.insert(b[m]);}
// //     }
// // m++;
// //    }
// //   //  for(int g=n-k+1;g<=n;g++){
// //   //   if(b[g]==-1)cnt++;
// //   //   else bb.insert(b[g]);
// //   //  }
// //    for(i=n-k+1;i<=n;i++){
// //     if(bb.find(a[i])!=bb.end())continue;
// //     if(cnt==0){
// //       NO;return;
// //     }
// //     cnt--;
    
// //    }
// //    YES;



//   //  set<int>wa;
 
//   //  for(int x:bb){
//   //   if(wa.find(x)==wa.end()){
//   //     NO;return;
//   //   }
//   //  }
//   //  YES;

//   //  for(int i=0;i<=n-k;i++){
//   //   if(b[i]==-1){
//   //     b[i]=a[i];
//   //     one.erase(i);
//   //     cnt--;
//   //   }else if (b[i]!=a[i]){
//   //     NO;return;
//   //   }
//   //   else {
//   //     bb.erase(b[i]);
//   //   }
//   //   if(m<n){
//   //     if(b[m]==-1){
//   //       one.insert(m);
//   //       cnt++;
//   //     }else {
//   //       bb.insert(b[m]);

//   //     }
//   //     m++;
//   //   }
//   //  }
// }
 
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