/*
Author: Pratyaksh Rai
Date: 2026-03-25
Time: 23:36:47
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


    if all its subarrays of length k have the same sum 
    

    currently n elements are there 

    you can insert elements from 1 to n 
    anywhere 

    dont minimize the number of inserted integer 



*/

// Small Observatins
/*

      why here  is 10^4  like n*n elements , 

      k<=n is also there ? 

      we can make it in n^2 elements in total ? 
      but how ? 


      k length subarray should have same sum ? 

      what to put on the sum ? 


      sabhi k length subarray ka sum same hona chahiye ? 
      
      for each number we can make permutation ? 
      right ? 

*/
//Your attacks
/*
dont think for any thing in the past , don't stick to that 
dont do that , please dont  atleast for adhock problems 
*/
// Hints From Code 
/*  
code by editorial 
*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/int N,K;
  cin>>N>>K;
  set<int>s;
  for (int i=0;i<N;i++){
    int a;
    cin>>a;
    s.insert(a);
  }

  if (s.size()>K){
    cout<<-1<<endl;
    return;
  }
  cout<<N*K<<endl;
  for (int i=0;i<N;i++){
    
    for (int b:s)
      cout<<b<<' ';
  
    for (int j=0;j<K-(int)s.size();j++)
      cout<<1<<' ';
  }
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