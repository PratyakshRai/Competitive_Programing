/*
Author: Pratyaksh Rai
Date: 2026-03-29
Time: 17:19:11
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


      a boys and b girls wish to participate 
      not all boys and not all girls are ready to 
      dance in pair 

      u know k possible (B G) pairs , you need to chooes 
      two of there pairs so that no person is in more that 
      one pair 




*/

// Small Observatins
/*
not all boys and girls ready to dance in pair 
 it means 
 bi <=b , so bi may not be equal to b , similarly for a's 
*/
//Your attacks
/*

        peechhe se chalenge , ye baat to pta chal gai 
         for a specific i , how many of them are 
         matching , or how many of them are not matching 
          how should i got to know this ? 

    try 1 : sum of both  numbers ? 
     nah  , (2,2) (3,1) this will fail 



    try 2 : pair banake sort kar diya  
     

     ai ko fix karke 
     ai se theek bda search karenge
     ie ai+1 

     but uske baad bi ka kaise 
     bi wala part pair se to match hi nhi kar rha 

     i can do frequency typo shit for b , yes 

     this works , right  ? 

     frequency ke liye kuchh aur hi karna padega 
     memory limit ka exceed kre 




    problem ? 

    how to store the frequency of the elements 
    suffix frequency ? 
    nope , simple frequecy karle bhai 

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/
int A,B,k;cin>>A>>B>>k;
vi a(k) ,b(k);
invec(a);
invec(b);
map<int,int>mp1,mp2;
for(int i=0;i<k;i++){
  mp1[a[i]]++;
  mp2[b[i]]++;
}
int ans=k*(k-1)/2;
int cnt=0;
for(int i=0;i<k;i++){
  cnt+=mp1[a[i]]-1;
  cnt+=mp2[b[i]]-1;
}
cout<<ans-(cnt/2)<<endl;



   
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