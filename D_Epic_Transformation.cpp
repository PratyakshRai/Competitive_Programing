/*
Author: Pratyaksh Rai
Date: 2026-03-26
Time: 18:04:59
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

        an operation is consists of several steps 

        we have to select two different numbers 
        and remove them from the array 


*/

// Small Observatins
/*

        we can separate 1 freq elements away from the array 

        like those having freq equal to 1 are separated in some other array  , and those having frequency greter than 1 are separated in some other 
        

        now create a multiset data structure for frequency of elements 
        pop the heighest freq element , then pop the after heightest frequecny element substract them , if 
        they >=1 then insert them in the array , or if they equal to 0 then dont 

        at the end if the size of the set is 1 answer that number , if the size if 0 answer 0 

        easy ;')



        substracting frequency is not a valid move ! 
        we have to some how distrubute the frequecies , but how ? 
        odd element dikkat de rha hai 

        chhote last odd element ko pick kiya 
        agar wo even hua to yes nothing will happen 
        if it is odd , then we have extra 1 in our hand 


*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
There is always a simpler solution for the question 
*/

int n;cin>>n;
vi a(n);
invec(a);
map<int,int>mp;
int maxfreq=0;
for(int i=0;i<n;i++){mp[a[i]]++;maxfreq=max(maxfreq,mp[a[i]]);}


if(maxfreq>n/2){
  cout<<maxfreq-(n-maxfreq)<<endl;
}
else cout<<n%2<<endl;


// // multiset<int>st;
// // int single=0;
// // for(auto it : mp){st.insert(it.ss);
// //   // else single++;
// // }
// // single=single%2;
// // if(st.size()%2!=0&&st.size()>=3){
// //   auto it =st.begin();
// //   int t=*it;
// //   st.erase(it);
// //   if(t%2!=0){
// //     single++;
// //     // single=(single+t)%2;
// //   }
// // }
// while(st.size()>1){
//   auto it1=prev(st.end());
//   int x=*it1;
//   st.erase(it1);;
//   auto it2=prev(st.end());
//   int y=*it2;
//   st.erase(it2);
//   x--,y--;
//   if(x>0)st.insert(x);;
//   if(y>0)st.insert(y);;
//   // int diff=x-y;
//   // if(diff!=0)st.insert(diff);
// }
// if(st.empty()){
//   cout<<"0\n";
//   return;
// }
// else cout<<*st.begin()<<endl;
// // if(st.size()==0){
// //   int f=single%2;
// //   cout<<f<<endl;;return;
// // }
// // if(*st.begin()==single){
// //   cout<<"0\n";return;
// // }
// // else if(*st.begin()>single){
// //   int t=*st.begin()-single;
// //   cout<<t<<endl;return;
// // }else {
// //   int t=single-*st.begin();
// //   t=t%2;
// //   cout<<t<<endl;
// // }
// // cout<<*st.begin()-single<<endl;
   
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