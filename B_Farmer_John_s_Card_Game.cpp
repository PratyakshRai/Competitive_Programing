#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
there is deck of n*m cards , m cards is distributed to n cows 

you want to make the game fair , so each one should only be able to play one card per round 

he decides to determine a turn order determined by permutation p of length n ;, such that pith cow will be the ith cow to place a card on the top of the center pile in a round , in other words following events happens in order in each round 


the pith cow places any card from their deck on top of the center pile 

there is a catch , initially the center pile contains a card numberered -1 , in order to place a card the number of the card must be the greater than the number of the card on top of the center pile , if a cow cannot place any card  in their deck the game is considered to be lost 

give such permutation so that all of his cows to empty their deck after playing all m rounds of the game 

*/
 
// Small Observatins
/*



*/
 
 
//Your attacks
/*
 kisi bhi cow ke deck me do lagatar no wale  card nhi hone chahiye 
 sort karne ke baad do consecutive card ka difference n ke brabar hoga 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n,m;cin>>n>>m;
   bool flag=false;
   vector<vector<int>>arr(n,vector<int>(m));
   for(int i =0;i<n;i++){
    vector<int>temp(m);
    for(int k=0;k<m;k++)cin>>temp[k];
    sort(temp.begin(),temp.end());
    for(int k=0;k<m-1;k++){
      int diff=abs(temp[k+1]-temp[k]);
      if(diff!=n){
        flag=true;
        break;
      }
    }
    
    arr[i]=temp;
   }
   if(flag){
    cout<<"-1\n";return;
   }
   vector<pair<int,int>>idx(n);
   for(int i=0;i<n;i++){
    idx[i].first=arr[i][0];
    idx[i].second=i+1;
   }
   sort(idx.begin(),idx.end());
   for(int i=0;i<n;i++){
    cout<<idx[i].second<<" ";
   }
   cout<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}