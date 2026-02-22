/*
Author: Pratyaksh Rai
Date: 2026-01-21
Time: 16:07:09
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
        we have a1+a2+a3...+an=x
        and then we have to tell what is the maximum value of gcd we can obtain , ie maximim of gcd(a1,a2,a3...,an);


        ab hame x ko n me divide karna hai , to if 
        x is divisible by n , then it is better to make all the elements same , otherwise ek ko adhik kiya to dusara kam hoga , aur gcd<=jo sabse kam hai 


        but if x%n!=0;
        so minimum gcd can be x/n
        but how to redistribute this
        how to redistribute x%n, among the arrays of n elements? 
        let say we have to distribute t=x%n, 
        and we have a as an element
        so if a+t%a==0 then the gcd will be a simple 
        but what about if a+t%a!=0 , then you cant make gcd greater equal to a 
        what we can do is to add n-1 , x/n times to a and each time we have to check wheather the new number is divisible by a-- or not ,  at the end a will be 1 so it is guarenteed 

        
*/
// Hints From Code 
/*  
EDITORIAL SOLUTION ;(
*/
void Chal_Ja_Plz(){
   int x, n;
   cin>>x>>n;
   int ans=0;
   for(int div=1;div*div<=x;div++){
    if(x%div==0){
      if(n*div<=x)ans=max(ans,div);
      int div2=x/div;
      if(n*div2<=x)ans=max(ans,div2);
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