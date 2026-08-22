/*
Author: Pratyaksh Rai
Date: 2026-02-23
Time: 20:48:42
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
   int n;cin>>n;
   vi arr(n);
   invec(arr);
   int ans=0;
   set<int>st;
   int prev=-1;
   vi values(1);
   for(int i=0;i<n;i++){
    int diff=arr[i]-prev;
    if(prev==-1){
      ans++;
      st.insert(arr[i]);
    }
    else if(diff==1)st.insert(arr[i]);
   else  if(diff>1){
      ans++;
      st.clear();
      st.insert(arr[i]);
    }
    else if(diff<=0){
      if(st.find(arr[i]-1)==st.end()){
        ans++;
        st.clear();
        st.insert(arr[i]);
      }
    }
    values.pb(ans);
    prev=arr[i];
   }
   
   vi suffix;
   int sum=0;
   for(int i=n;i>=1;i--){
    sum+=values[i];
    suffix.pb(sum);
   }
   /*
   values
   0 1 1 1 1 1 
0 1 2 3 4 5 
0 1 1 2 2 3 
0 1 1 2 2 3 4 4 
0 1 2 2 3 3 3 3 3 3 


5 4 3 2 1 
15 14 12 9 5 
9 8 7 5 3 
17 16 15 13 11 8 4 
23 22 20 18 15 12 9 6 3 

   */
  int final=0;
  int idx;
   reverse(all(suffix));  
   for(int i:values)cout<<i<<" ";
   cout<<endl;
   int curr=values[1];
   int i=1;
   int pre=0;
   int cnt=0;

   for(i;i<=n;i++){
    if(curr==values[i]){
      
      final+=(n-i+1)*pre;
    }else {
      pre=curr;
      curr=values[i];
      final+=(n-i+1)*pre;

    }
   }

  //  final+=(i-idx)*pre;
  //  cout<<endl;
  int z=accumulate(suffix.begin(),suffix.end(),0LL);
  
   cout<<z-final<<endl;
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