#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define end '\n' 
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vi vector<int>
#define ff first
#define ss second
// Common constants
const int INF = 1e18;
const int MOD = 1e9 + 7;

// Common directions for grid problems
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Problem Statement
/*
non negative hai 
partially filled hai 

blank pe -1 hai 
non negative se fill karna hai blank ko 
difference array ko minimized kar hai 

let supose x x x -1 x x x hai 
ab -1 pe kya rakhna chahiye ? 
to same adjcent element rakhne se kaam bn jayega , but kaunsa 
jo adjacent sabse bda ho 
to ek triplet ko utha sakte hai 



lol agar ham expansion ko khole ie
ai+1-ai
to at the end an-ai bach jayeg  ;>

*/

// Small Observatins
/*

*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int &i:arr)cin>>i;
   if(arr[0]==-1&&arr[n-1]==-1){
    arr[0]=0;
    arr[n-1]=0;
   }
   else if(arr[0]==-1){
    arr[0]=arr[n-1];
   }
   else if(arr[n-1]==-1){
    arr[n-1]=arr[0];
   }
   cout<<abs(arr[n-1]-arr[0])<<"\n";
   for(int i=0;i<n;i++){
    if(arr[i]==-1)cout<<"0 ";
    else cout<<arr[i]<<" ";
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
/*
Three golden rules : 
1.Every problem has a solution 
2.Every problem has a simpler solution 
3.Understand what the problem is point to 

*/