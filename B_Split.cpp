/*
Author: Pratyaksh Rai
Date: 2026-01-19
Time: 20:50:06
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
        f(a) hame no of distinct element batayega with odd no of occurence 
        means 5, 555, 55555, rha to function 1 dena but 55 .. rha to 0 , 
        like if 2,5,5, par 1 dega , aur 2 ,5,5,5 par 2 dega 


        ab hame array a ko subsequence me todna hai ie p and q such that f(p)+f(q)
        is maximized 




        agar distinct elements hai , to kisi me daalo pharak nhi padega 
        but let if the frequency is greater than 1 

            if it is even , then we can split it into two odds and put them in separate and they will carry only 2 weight 
                but if it is odd it is better to keep it in one seq ,as odd will break into two evens , no use 


  ab set bna liya aur freq bhi store karli 
  aur jha jha freq even hue a++ aur jha odd no change 
      Wrong move , we have to make p and q  each of n length with no common element share between them ";(";


      cases : agar no of distinct element even hai tb to dono me divide kar denge 
            distict elements + total sum of all the no of non distinct elements =2*n
            hence total sum ... is also even
            like even + even +even .. 
            odd +odd, odd+odd+odd+odd ke form me honge 
        
      no of distinct element odd hua to bche hue elements bhi odd honge, 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n ;cin>>n;
   n=2*n;
   map<int,int>mp;
    for(int i=0;i<n;i++){
    
    int x;cin>>x;
     
    if(mp.find(x)==mp.end()){
      mp[x]=1;
    }else mp[x]++;
   
   }
   int ans=0;
   int even=0, odd=0;
   int dis=0;
    for(auto &p: mp)if(p.ss%2==1)dis++;
      for(auto &p: mp){
    if(p.ss%2==1)ans++;
    else if(p.ss%2==0){if((p.ss/2)%2!=0)ans+=2;
    else even++;}
    else ans++;
   }
  //  cout<<ans<<endl;
  ans+=4*(even/2);
  if(even%2!=0&&dis!=0)ans+=2;
cout<<ans<<endl;
  // wrong move map<int,int>mp;
  //  set<int>st;
  //  for(int i=0;i<n;i++){
    
  //   int x;cin>>x;
  //    st.insert(x);
  //   if(mp.find(x)==mp.end()){
  //     mp[x]=1;
  //   }else mp[x]++;
   
  //  }
  // //  for(int it : st)cout<<it<<" ";
  // //  cout<<endl;
  // //  cout<<st.size()<<endl;
  //  int ans=st.size();
  //  for(auto &p: mp){
  //   if(p.ss%2==0)ans++;
  //  }
  //  cout<<ans<<endl;
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