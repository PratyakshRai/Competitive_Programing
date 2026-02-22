#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define end '\n' 
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vi vector<int>
#define ff first
#define ss second
// Common constants
const int INF = 1e18;
const int MOD = 1e9 + 7;

// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Problem Statement
/*
two array given hai , 
one game should be played for n turns 
A - will move on  odd numbered turns 
B- will move on even numbered turns 
on the ith turn the player to move may choose to swap ai and bi or pass 
A - can swap odd indices 
B- can swap even indices 


xor - same no  ie even no of numbers ka xor 1 hota hai ie 2 xor 2 xor 2 xor 2  will be zero 
so both will try to make  no of one in their array odd 


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
   int n;cin>>n;
   vi arr(n);
   vi brr(n);
   for(int &i : arr)cin>>i;
   for(int &i : brr)cin>>i;
   string s ="";
   int a=0,m=0;
   int A=arr[0];
   int M=brr[0];
   for(int i=1;i<n;i++){
    A=A^arr[i];
  M=M^brr[i];
   }
   int l=0;
   for(int i=0;i<n;i++){
    if(i%2==0){
      if(arr[i]^brr[i]==1){a++;l=i+1;}
    }
    else {
      if(arr[i]^brr[i]==1){m++;l=i+1;}
    }
   }
 int t=a+m;
 if(t%2==0){
  cout<<"Tie\n";return;

}
else {
  if(l%2!=0){
    cout<<"Ajisai\n";return;
  }
  else cout<<"Mai\n";
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