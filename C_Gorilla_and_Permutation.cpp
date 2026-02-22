#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
    
*/
 
// Small Observatins
/*

1. n,m,k    m<k;

2.permutation bnana hai 

3. f(x)-g(x) karna hai , jha fx aur gx prefix sum hai , fx me wo sum hai jo hi >=k hai  , aur gx me <=m;


solution : 
to agar maine starting me hi >=k wale elements ko rakha ? 
baad me wo elements khatam ho jane par bache hue ayenge

to hamare paasss elements hai 

x<=m    m<x<k   k<=x

ab inko kaha aur kaise lagana hai


ab kyuki gx ko minimize karna hai to ham gx ke elements bharte time 
accending order me bharenge 

lets go 




*/
 
 
 
/*
 
*/
 
 
// Claims on algo 
/*  
    
 
*/
 
 
void solve(){
   int n,m,k;cin>>n>>m>>k;
   for(int i =n;i>m;i--){
    cout<<i<<" ";
   }
   for(int i=1;i<=m;i++){
    cout<<i<<" ";
   }
   cout<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}