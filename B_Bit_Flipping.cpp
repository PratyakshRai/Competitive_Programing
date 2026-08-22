/*
Author: Pratyaksh Rai
Date: 2026-02-25
Time: 10:12:16
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

      we are given k and string 
      if k==0 cout s
      if k==1 
      how to make the string lexo largest
      choose first 1 appreance from left to right 

      0 0 1 1 1 0
      1 1 1 0 0 1 
      if k is odd then it is the answer 

      other wise 
      let k=2
      0 0 1 1 1 0 
      1 1 1 0 0 1 
      select msb 
      1 0 0 1 1 0 
      k=3 pe wapas se isko select kar dunga
      1 1 1 0 0 1 
      koi fayda nhi dikh rha 

      what if i choose 0 and then 1 

      0 0 1 1 1 0 
      0 1 0 0 0 1 
      1 1 1 1 1 0

      mean for every k/2 operation i can increase 
      1 by 2 
      so k is either even or odd , 
      if it is even then let k=12 
      so k/2 =6 , but i can increse the bit 
      at max 2 more 
      for the rest of the time i just spam it 

      if k is odd then i will use one k to flip
      
      it is sorted for k even 


      
      















*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,k;cin>>n>>k;
   string s;cin>>s;
   vector<int>o,z;
   for(int i=0;i<n;i++){
    if(s[i]=='1')o.pb(i);
    else z.pb(i);
   }
   vector<int>ans;
   if(k%2!=0){
    int t=*o.begin();
    ans.pb(*o.begin());
    o.erase(o.begin());
    for(int i=0;i<n;i++){
     if(i!=t) {
      if(s[i]=='0')s[i]='1';
      else s[i]='0';}
    }
    
    // cout<<k<<" ";
    //     cout<<s<<endl;
    //     k--;
   }
   int can=k;
   int zero=count(s.begin(),s.end(),'0');
   if(zero%2!=0)zero--;
   int req=min(zero,can);
   for(int i=0;i<n&&req>0;i++){
    if(s[i]=='0'){
      s[i]='1';
      ans.pb(i);
      req--;
    }
   }
   cout<<s<<endl;
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