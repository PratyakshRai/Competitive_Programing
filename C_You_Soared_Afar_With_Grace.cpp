/*
Author: Pratyaksh Rai
Date: 2026-04-02
Time: 15:54:59
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

      we have a permutation a and b of length n 

      we can perform the operaton atmost n times 

      choose two diff indexes i and j , i!=j 

      swap ai with aj 
      swap bi with bj 

      determine wheater a and b can be reverse of each other 


      dekha jaye to ai bi se map ho rakha hai 

      aur ye jaruri nhi ki 
      a ya b sorted ho 







*/

// Small Observatins
/*

*/
//Your attacks
/*



                            odd length me ayesa condition jarur ayega 
                            jime 
                            ai=bi ho jaye ; otherwise not possible ? right ? 


          isnt it simple ? 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
int n;cin>>n;
vi a(n);
vi b(n);
vi ai(n+1),bi(n+1);
invec(a);
invec(b);
int mid=0,cnt=0;
for(int i=0;i<n;i++){
  ai[a[i]]=i;
  bi[b[i]]=i;
  if(a[i]==b[i]){cnt++;mid=i;}
}
if(cnt>1){
  cout<<"-1\n";return;
}
if(cnt==1&&(n%2==0)){
cout<<"-1\n";return;
}
vector<pair<int,int>>ans;
int tempidx=n/2;
if(tempidx!=mid){
swap(a[mid],a[tempidx]);
swap(b[mid],b[tempidx]);
ai[a[mid]]=mid;
ai[a[tempidx]]=tempidx;
bi[b[mid]]=mid;
bi[b[tempidx]]=tempidx;
ans.pb({mid+1,tempidx+1});}
vi visited(n,false);
for(int i=0;i<n;i++){
  if(!visited[i]){
    visited[i]=true;
  int x=a[i];
  int y=b[i];
  int fy=bi[b[i]];
  int t=bi[a[i]];
  int ft=a[t];
  if(a[bi[a[i]]]!=b[i]){
    cout<<"-1\n";return;
  }
  int idx=n-1-i;
  visited[idx]=true;
  if(t==idx)continue;
  swap(a[idx],a[t]);
  swap(b[idx],b[t]);
  ai[a[idx]] = idx;
ai[a[t]] = t;

bi[b[idx]] = idx;
bi[b[t]] = t;
  ans.pb({idx+1,t+1});

}}
// for(int i:a)cout<<i<<" ";
// cout<<endl;;
// for(int i:b)cout<<i<<" ";
// cout<<endl;
// cout<<endl;

if(ans.size()==0){
  cout<<0<<endl;return;
}
cout<<ans.size()<<endl;
for(auto it :ans)cout<<it.ff<<" "<<it.ss<<endl;
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