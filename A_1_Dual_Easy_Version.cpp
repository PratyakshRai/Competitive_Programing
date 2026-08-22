/*
Author: Pratyaksh Rai
Date: 2026-03-07
Time: 18:15:02
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

        we can have +ve -ve and 0 
        so we can choose two  element at a time 

        they can be same also 
        ai=ai+aj , and do this 

        in atmost 50 operation we have to make the array 
        non decreasing , ai<=ai+1





*/
//Your attacks
/*

      n is very small , ie 20 , 
      a1 is very small is it can be -20

      by using 21 operation if we create largest element 
      like ai=ai+ai , 21 times , what will be the minimum 
      value for that ai , let ai is the largest 


                if ai is -ve , then it become more -ve 
                is , let it is -20 then it become -420 

                if ai is 0 , then is become 0 
                if ai is +ve then it become , +420 

                how to use this ? 

                1 , 2  ,3 , 4 , 5, 6 , ,,sum of n natural number
                is 20(20+1)/2
                which is 210 , way more huge than 50 

                we have to do something else ? 

                we cant do anything 

                let take no dec order
                : 
                1 2 3 4 5 6 5 4 3 2 1 
                what if we take 
                prefix sum typo shit 
                1 3 6 10 15 21 .. it will be in increasing order 
                but if -ve elements come ? 
                1 2 3 4 5 -20 -20 ...
                1 3 6 10 15 -5 (problem here )
                so 
                we can eleminate this -ve by adding some greater +ve value
                right ? 
                we will use that highest +ve element we created here 
                ie to make all the negatives >=0

        but what is all are negative ? 

              -1 -2 -3 -4 0 -5 ..
              we can do suffix sum 
             ...-12 -9 -5 -5




*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n;cin>>n;
   vi a(n);
  //  vector<pair<int,int>>ans;
   invec(a);
   int mx=-INF,mn=INF;
   int idm,idn;
   for(int i=0;i<n;i++){
    if(a[i]>mx){
      mx=a[i];
      idm=i;
    }
    if(a[i]<mn){
      mn=a[i];
      idn=i;
    }
   }
   if(is_sorted(all(a))){
    cout<<"0\n";return;
   }
   if(mn==0&&mx==0){
    cout<<"0\n";return;
   }
   vector<pair<int,int>>ans;
   if(abs(mx)>=abs(mn)){
    for(int i=0;i<n;i++){
      if(a[i]<0){
        ans.pb({i+1,idm+1});
      }
    }
    for(int i=1;i<n;i++){
      ans.pb({i+1,i});
    }
   }
   else{
    for(int i=0;i<n;i++){
      if(a[i]>0){
        ans.pb({i+1,idn+1});
      }
    }
    for(int i=n-2;i>=0;i--){
      ans.pb({i+1,i+2});
    }
   }
   cout<<ans.size()<<endl;
   for(auto it: ans)cout<<it.ff<<' '<<it.ss<<endl;

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