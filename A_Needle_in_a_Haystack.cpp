/*
Author: Pratyaksh Rai
Date: 2026-01-19
Time: 10:29:00
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
      letter kitne hai ye count karna 
      phir use kitne karne hai ye 
      phir ek pointer first wale pe  , aur neeche wala iterate kar rha hoga 26 alphabets par , 
          jaha same hue alphabets , waha pointer++
          par agar first wala chhota nikale , to use it fast 
*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   string first,second ;cin>>first>>second;
   vector<int>frf(27),frs(27);
   for(int i=0;i<first.size();i++){
    frf[first[i]-'a']++;
   }
   for(int i=0;i<second.size();i++){
    frs[second[i]-'a']++;
   }
   for(int i=0;i<26;i++){
    if(frf[i]>frs[i]){
      cout<<"Impossible\n";
      return;
    }
    else {
      frs[i]-=frf[i];
    }
   }
   int k=0;
   for(int i=0;i<26;){
    if(k<first.size()&&(first[k]<=i+'a')){
      cout<<first[k];
      k++;
    
    }
    else {
      
      
        char ch=i+'a';
      while(frs[i]>0){cout<<(ch);frs[i]--;}
      i++;
    }
    
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
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/