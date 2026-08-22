/*
Author: Pratyaksh Rai
Date: 2026-03-10
Time: 20:11:32
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

      so we have two arrays of length n 

      so we can reorder it , any array , any way , 
      to restrictions 

      then perform some operations 

      in one operations , you have to do 
      two things : 
                    1.choose an element from 
                    a and remove it 
                    2. similarly from b 

        let k be the final size of both the array 
        you need to find the minimum operations required 
        to achieve ai<bi for i<=k 

        but now , 
        you are given  m = 1 (here only )

        and you need to find the sum of answers 
        to the problem for m pairs of array 

        (c[i],b), where  
        c[i] is obtained from a as follows : 

            here there is only one  ie m=1
            hence  c[i] will have only one value 
            which is , 

            c[1] , which will equal to 

            [ 1 , a2 , a3 , a4 , a5 , ... , an]


*/

// Small Observatins
/*

      now the problem breaks into 
      you have two array , 

      you can reorder it as you wish 

      make less operations means ,increase the length if possible 

      such that ai<bi for every length of the array 

*/
//Your attacks
/*

   iterate karenge b pe , aur a ki value nikalenge 
   like if 3 se chhota koi hai ki nhi 
   or you can opposite it 

   a par iterate karenge , aur 
   a[i]<b[i] just  , aur us just ko remove kar denge 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,m;cin>>n>>m;
   vi a(n);
  a[0]=1;
  for(int i=1;i<n;i++)cin>>a[i];
  sort(all(a));
  multiset<int>b;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    b.insert(x);
  }
  int ans=0;
  reverse(all(a));
  for(int i=0;i<n;i++){
    int val=a[i];
    auto it =b.upper_bound(val);
    if(it!=b.end()){
      b.erase(it);
    }
    else {
      ans++;
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