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
   to agar <* ya >* ya ** ya >< dikhe to -1 
   otherwise we have to calculate the maximum no of continuouse < or > 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
  
   string s;cin>>s;
   int n =s.size();
   if(n==1){
    cout<<1<<"\n";
    return;
   }
   int less=count(s.begin(),s.end(),'<');
   int great=count(s.begin(),s.end(),'>');
   
   for(int i=0;i<n-1;i++){
    if((s[i]=='>'&&s[i+1]=='*')||(s[i]=='*'&&s[i+1]=='<')){
      cout<<"-1\n";return;
    }if(s[i]+s[i+1]==84){
      cout<<"-1\n";return;
    }
    if(s[i]=='>'&&s[i+1]=='<'){
      cout<<"-1\n";return;
    }
   }
   for(int i=0;i<n;i++){
    if(s[i]=='>'){
      int j=i;
      while(j<n){
        if(s[j]=='<'){
          cout<<"-1\n";
          return;
        }
        j++;
      }
      break;
    }
   }
  //  cout<<s<<endl;
   int ans=0;
   int t=0,h=0;
   bool flag=false;
   for(int i=0;i<n;i++){
    if(s[i]=='<'||s[i]=='*'){t++;flag=true;}
    else if(flag)break;
   }
   flag=false;
   for(int i=0;i<n;i++){
    if(s[i]=='>'||s[i]=='*'){h++;flag=true;}
    else if(flag)break;
   }
   cout<<max(t,h)<<endl;;
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