/*
Author: Pratyaksh Rai
Date: 2026-03-03
Time: 18:30:39
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
    we have to insert exactly n-2 symbols

    what does this means  

          x1  x2  x3  x4  x5  x6  x7  x8  x9 

          so in this we can insert 7 symbols 

              and there are 8 spaces  , 1 extra space ? 

              symbols are , we can either use "x" or "+"

              now how to minimize them ? 

              0 ke aas paas X rhega to wo us no ko kha jayega 
              1 se aas pass X rhega to wo us no ko age badne nhi 
              dega , like 2X1=2  where as 2+1=3 

              other than this , every numbe should have
              + on their left or right 

              like 5+5 type shit 

              now we will choose the smallest 
              2 digit in the string
              
              so that is the greedy to choose the number ? 

              i think first  i will distribute the sysmbols 
              and then i will remove any one sysmbol and then find the 
              answer , but it will cause n^2
              
              but how even i can calculate the mathematical expression ? 
              
              how to calculate 2X2X2+2  ? , how to do this shit 


              

          

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n;cin>>n;
string s;cin>>s;


if(n<=2){
  cout<<stoi(s)<<endl;
  return;
}
int ans=INF;
for(int i=0;i<n-1;i++){
  vi store;
  for(int j=0;j<i;j++)store.pb(s[j]-'0');
  store.pb(stoll(s.substr(i,2)));
  for(int j=i+2;j<n;j++)store.pb(s[j]-'0');
  int sum =0;
  for(int i: store){
    if(i==0){
      cout<<"0\n";
      return;
        }
        if(i!=1)sum+=i;
  }
  if(sum==0)sum=1;
  ans=min(ans,sum );

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