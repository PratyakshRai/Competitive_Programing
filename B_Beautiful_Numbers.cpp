/*
Author: Pratyaksh Rai
Date: 2026-02-25
Time: 20:12:01
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
  if the number is onces the f(f(x))=f(x);

  no leading zeros 
*/
//Your attacks
/*

*/
// Hints From Code 
/*  
claim , put first place digit as one (if not one )
      then after first digit ,
          iterate and select all non zero
            and delect any one of the except 9 
            1 0 0 0 0 3 0 0 type thing 
            it will make f(f(x)=4)=f(x)=4

      further clarification 
      choose first number x and then any number y 
      such that x+y <=9 and make all the other zero      
      
    further clarification 
    pahale number ko 1 rakha aur dekha kitne ko select kar sakte hai 
    agar pahala numebr pahale se 1 tha then no ++ if not then ++
    then sort the rest of them and select till the sum<=9, and erase the rest of them   

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   string s;cin>>s;
   vector<int>a;
   int init=s[0]-'0';
   for(int i=1;i<s.size();i++){
    a.pb(s[i]-'0');
   }
   sort(all(a));
  //  for(int i:a)cout<<i<<" ";
  //  cout<<endl;
   int ans=s.size();
   for(int i=1;i<=9;i++){
    int cnt=0;
    int sum=0;
    sum+=i;
    if(i==init)cnt++;
    for(int j=0;j<a.size();j++){
      if(sum+a[j]<=9){
        cnt++;sum+=a[j];
      }else if(sum+a[j]>9)break;
    }
    
    // if(i!=init)
    ans=min(ans,(int)s.size()-cnt);
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