/*
Author: Pratyaksh Rai
Date: 2026-03-19
Time: 22:30:16
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

            so we have n rooms with its light turned off; 

                each room has exactly one chip , right ? 
                the chips are installed at different time 

                ai is the chips time installation 

                as soon as the chip is installed it changes the 
                room light every k miniutes 
                ie ai + pk , for every time it changes the status for the light 

                earlist moment when all rooms in the apartment have their light turn on ? 


                if there is no such momonet  -1 




*/

// Small Observatins
/*

*/
//Your attacks
/*
sabse pahale to sari lights install kro , 

        inme ek commom interval nikal ke aa rha hai , how should i pick the smallest from those interval ? 

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,k;cin>>n>>k; 
   vi a(n);invec(a);
   
   sort(all(a));
   int first = a[n-1];
   reverse(all(a));
   int L=a[0],R=L+k-1;
   int currl=a[0];
   int currr=a[0]+k-1;
   for(int i=0;i<n;i++){
    int diff=a[0]-a[i];
    int cycpos=diff%(2*k);
    int cl,cr;
    if(cycpos<k){
      currl=a[0];
      currr=a[0]+k-1-cycpos;
    }
    else {
      currl=a[0]+(2*k-cycpos);
      currr=currl+k-1;
    }
    L=max(L,currl);
    R=min(R,currr);
   }
   if(L<=R){
    cout<<L<<endl;
   }
   else {
    cout<<"-1\n";
   }
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