/*
Author: Pratyaksh Rai
Date: 2026-01-22
Time: 18:04:02
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
    agar length odd hai to minimum possible 1 
        and if even then it is 0 
        can we achieve it ? 
        how to achieve it ? 
        how to minimeze the length? 



        kya ayesa koi possiblity bann rha hai jisme ek pair select karne se future me no of delection kam ho jayega ? 
                  yes , like a r c a a, we cant select the pair {r,c}

        the idea is to remove the frequency of the repeated elements then we can choose to remove the other s          
*/
// Mistake , why didnt you able to solve this problme 
/*  
      always remember there is a easier solution 

      i got stuck into solving the problem by bruteforce
      without observing what is going to happen
*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   string s;cin>>s;

   map<char,int>mp;
   for(char ch:s){
    mp[ch]++;
  }
  int mx=0;
  for(auto it :mp){
    mx=max(mx,it.ss);
  }
  cout<<max(n%2,2*mx-n)<<endl;
  //  cout<<mp.rbegin()->ff<<endl;
  //  char prev='1';
  //  for(int i=0;i<n;i++){
  //   int ch=s[i];
  //   if(prev==ch)continue;
  //   if(prev=='1'){prev=ch;continue;}
  //   if(mp[prev]==1&&mp[ch]==1){
  //     cnt++;
  //     prev=ch;
  //     if(i==n-1)cnt++;
  //   }
    
  //   else {
  //     rem+=2;
  //     mp[prev]--;
  //     mp[ch]--;
  //     prev='1';
  //   }
  //  }
  //  cout<<rem<<" "<<cnt<<endl;
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