/*
Author: Pratyaksh Rai
Date: 2026-03-04
Time: 18:42:39
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
            we have a permutation of length n 

            there is an alternate move between alice and bob 

            now the player on his/her move has to move the chip 

            it can me move to left (any one in the left side ) also the element should be 
            smaller than the current element
            
            like let it is move to j 
            then j<i and aj<ai


            the ith element is said to be lucky if 
            alice on her firt move place the chip on the ith element 
            and she can win the game 
            no matter bob plays 

            now we have to calculate the number of lucky elements
            ? 

          
            
solving :       in order to win alice , 


                let alice place coin in 5th place 
                then there must be an element smaller 
                than that in the left side , and 
                after that element no one is smaller 

                hence bob will play to that element 
                and since no smaller element is after
                that , alice will win 


                so for each element , usse smaller koi hua 
                pahale let x , so x se sab bade ho 
                
                like let you choose ith , 
                so ith se smaller koi hai 
                if han , then usse smaller koi hai 
                if nah , then cnt++






*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n;cin>>n;
vi a(n);
invec(a);
int cnt=0;
int first=INF;
int sec=INF;
for(int i=0;i<n;i++){
  if(first>a[i]){
    first=a[i];continue;
  }
  if(sec>a[i]){
    cnt++;
    sec=min(a[i],sec);
  }
}




cout<<cnt<<endl;

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