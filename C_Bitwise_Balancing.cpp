/*
Author: Pratyaksh Rai
Date: 2026-03-06
Time: 22:17:48
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
      
        0 is also possible  

        b c and d 

        if(b and d is equal , the answer is 0 )

        we can say we want
             a|b = a&c+d ? 

            is this and operation saying something ? 

            b aur d ko dekho 
            
              jo bit d me nhi hai use b se bhi htana hai 
              aur htane ka ek hi option hai 
              and operation , us bit ko jisse htana hai , wo c
              me hona chahiye , otherwise khel khatam 

              vivevesa jis bit ko set karna hai b me kyuki wo d me set 
              hai , us bit ko c me nhi hona chahiye , that's it 


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
 int b,c,d;cin>>b>>c>>d;
 if(b==d){
  cout<<"0\n";
  return;
 }
 int ans=0;
 int mx=63-__builtin_clzll(max(b,d));
 for(int i=0;i<=mx+1;i++){
 int B = (b >> i) & 1;
int C = (c >> i) & 1;
int D = (d >> i) & 1;
  if(B==D)continue;
  bool flag=false;
  for(int a=0;a<=1;a++){
    int val=((a|B)-(a&C));
    if(val==D){
      flag=true;
      if(a)ans|=(1LL<<i);
      break;
    }
  }
  if(!flag){
    cout<<"-1\n";
    return;
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