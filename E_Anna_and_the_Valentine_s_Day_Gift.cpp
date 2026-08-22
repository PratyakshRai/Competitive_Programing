/*
Author: Pratyaksh Rai
Date: 2026-03-10
Time: 15:35:23
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

      we have to distroy the list 

      she will make the first turn 

      on her turn , she must(<-) choose element and reverse its digits 

      after her turn , the number of element does not changes 

      on his turn , he must choose two elements and concanate it in 
      any order  and then add it to then end of the array 


      the games end if he cant make any move , like 

      let 2 element is present rigth now , then he choose and concanate it 
      now 1 element is there  , she do her operation  , now he cant do anything 

      so if the final integer is >= 10^m he wins otherwise she wins 




*/

// Small Observatins
/*

      the number to compare is in the power of 10 

      if you have 121210000 ,then she will choose to reduce it 
      like 
             it become 12121 


*/
//Your attacks
/*

          so all the numbers given can be categories into 
          
              two groups  , one with type : 12134000 ( zeroes at the end )
                              other with type : 1212121 (no zerores at the end )


        suppose we have the numbers with no zeores at the end , 

        it is such a waste for she to choose this number , as nothing gonna happens 

        now comes to numbers with zeroes at the end 

        how will he saves those numbers ? 

        he will  concanate those numbers , but to choose which number , to whom he should 
        concanate , 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n,m;cin>>n>>m;
   string ans="";
   vector<pair<int,int>> b;
   for(int i=0;i<n;i++){
    int x;cin>>x;
    if(x%10==0){
      int z=0;
      int temp=x;
      while(temp%10==0){
        temp=temp/10;
        z++;
      }

      b.pb({z,x});
    }
    else ans+=to_string(x);
   }
   sort(all(b));
   reverse(all(b));
   for(int i=0;i<b.size();i++){
    string s=to_string(b[i].ss);
    if(i%2==0){
    reverse(all(s));
    int val=stoll(s);
    s=to_string(val);
  }
  ans+=s;
   }
   if(ans.size()>m){
    cout<<"Sasha\n";
   }else {
    cout<<"Anna\n";
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