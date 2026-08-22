/*
Author: Pratyaksh Rai
Date: 2026-03-19
Time: 14:45:11
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

    you want to reward k employees with a ticket 

    ticket will be on sale for n days 

    price per ticket at day i will be ai 


    to prevent scam , 
    some rules are made : 

          a person may purchase no more that m ticket per day 

            if  a person purchase  x tickets on day i , all subsequent days will have their prices per ticket increased by x 
            
            
            you have to tell the minimum spending to purchase k tickets  


            


*/

// Small Observatins
/*

*/
//Your attacks
/*

      ek din me m tickets se jyada nhi kharid sakte  , 
       

            minimum spendings to purchase k tickets 

            can i do binary search on the monkey , since more money = more tickets 



            now the question breaks into ,you have to buy k tickets in x money will you be able to do it or not  with follows the conditions 






*/
// Hints From Code 
/*  
ye question kyu nhi hua  , question ko mai bahut tough maan leta hu 
jabki wo itna tough hota nhi hai , 
kami kaha rah jati hai ? 

aato proper observation pakadne me 
wo kyu nhi kar pata , kyuki proper dry run nhi karta hum 




*/
bool can (vector<int>&a,int  m , int k , int money){
  int multi=-1;
  int n=a.size();
  int required=0;
  int curr=k;
  for(int i=0;i<n;i++){
     if(curr<=0)break;
    if(required>money)return false;
    int t=min(curr,m);
    required+=a[i]*t;
    if(multi==-1){
      multi=t;
    }else {
      required+=t*multi;
      multi+=t;
    }
    curr-=t;
    if(curr<=0)break;
    if(required>money)return false;
  }
  if(required<=money)return true;
  return false;

}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,m,k;cin>>n>>m>>k;
   vi a(n);invec(a);
   int ans=0;
   sort(all(a));
   int low =0,high=2e18;
   while(low<=high){
    int  mid=(low+high)/2;

    if(can(a,m,k,mid)){
      ans=mid;
      high=mid-1;
    }
    else low=mid+1;
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