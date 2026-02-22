#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek permutation diya gya hai , aur dusra index ki ek array ,

ab index ki array ke hisaab se pemutation se elements delect karne hai , aur har delet par btana hai ki permutation ko restore , ya to pahale ki tarah yato koi naye permutation bnane ke liye kitne operation lagenge

ek operation me tum a[i] ko i likh sakte ho

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 to pahale index choose karenge aur agar us index par jo element hai wo agar apne i ke brabar hua to +1 otherwise +2
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*

ek nayi tarika seekha , jisse ham boom 

pahale usindex pe gaye jha zero karna tha , wha zero karne ke baad ham us par jo bhi rha hoga usse restore karne gaye , aur us index par jake use restore kar diya , ab ye bhi ho sakta hai ki restore karne ke baad , 2 , , , , 2 aaye , aur last wale 2 ke liye order aaya ho , to hame to pta hi hai ki index 2 par jo 2 hai wo to dusare wale ki wajah se restore ho hi rha hai 


*/
 
 
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   for(int &i:arr)i--;
   set<int>st;
   for(int i=0;i<n;i++){
    int d;cin>>d;
    d--;
d=arr[d];
    while(!st.count(d)){
      st.insert(d);
      d=arr[d];
    }
    cout<<st.size()<<" ";
   }
   cout<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}