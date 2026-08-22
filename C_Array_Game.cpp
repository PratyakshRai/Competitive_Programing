/*
Author: Pratyaksh Rai
Date: 2026-03-06
Time: 22:51:53
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

          so what we have to do is : 

          choose two different element : ai and aj  
          and append to the end of the array the abs(ai-aj) 

          now we have to create the minimum value possible 


          what are the things given  
                 we can do n^2 
                 but we cant do even a full iteration on k 
                 that is the problem 

                 we have to tell before iterating on k full , the 
                 the minimum possible ? right ? 

                 how to do this ? 

                 what is the meaning of iterating n^2 ,where it is pointing to ? 

                 
attacks: 
    

      if k>=3 , i will choose any two element  , let say a1 and a2 , add d=(abs(a1-a2));
                                                        then again i will choose the same 
                                                        a1 and a2 , again i will get 
                                                        d 
                                                        now the third time i will choose 
                                                        two same numbers , d  and d 
                                                        and the minimum possible will become d
                      hence for k>=3 , then answer is 0 lol
                      
                      for k =1 , it is shorted , we will iterate n^2 , 
                      and cout<< min(mn , abs(ai-aj))

                      but what about k=2 ? 
                       
                      approach 1: 

                      agar ham do baar k=1 wala step kare to kya gaurentee 
                      hai ki hame minimum millega 

                      the thing is , we have find any d (abs(ai-aj)) , which is 
                      as close to any element in that array 

                      okay , first we store all the difference d (abs(ai-aj))
                      
                      now we have two arrays , difference d array and the og 
                      array ,
                      now we have to find the minimum element by doing the same thing 
                      

                      i have one idea , for even element in og array , 
                      i will find ki is element se just brabar ya bda 
                      aur is element se just chota  , it will cause n*log(n^2);

                      and all set ;")
                    



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
int n,k;cin>>n>>k;
vi a(n);invec(a);
if(k>=3){
  cout<<"0\n";
  return;
}
sort(all(a));
vi b;
for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
    b.pb(abs(a[i]-a[j]));
  }
}
sort(all(b));
if(k==1){
  if(n!=1)
  cout<<min(a[0],b[0]);
  else cout<<a[0];
  cout<<endl;
  return;
}
int mn=min(a[0],b[0]);
int ans=INF;
for(int i=0;i<n;i++){
  int x1=INF,x2=INF;
  int x=a[i];
  int cnt=INF;
  auto it =lower_bound(b.begin(),b.end(),x);
  if(it!=b.end()){
    cnt=min(cnt,(abs((*it)-x)));
  }
  if(it!=b.begin()){
    cnt=min(cnt,(abs((*(prev(it)))-a[i])));
  }
  ans=min(ans,cnt);
}
// int diff2 = INF;
// for(int i=1;i<b.size();i++){
//     diff2 = min(diff2, b[i]-b[i-1]);
// }

// for(int i:b)cout<<i<<" ";
// cout<<endl;
// cout << min({ans, mn, diff2}) << endl;
cout << min({ans, mn}) << endl;

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