/*
Author: Pratyaksh Rai
Date: 2026-03-08
Time: 18:07:42
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

    we have marbles of n different colors : 

    alice got ai marbles of color i , and bob got bi marbles of color i 

    the range for ai , bi (1,10^9)


    now there is a game : 

                  alice first 

                  so the player on his turn , chooses a color i ,such that both 
                  will have that color available , and then that player will discard one of the color of i , and the opponent will discard all of the color of 
                  i 
                  the game ends when there is no color i common between them , right? 

                  what is the score for the game , ie , the score 
                  is ,(a - b ) , where a is the number of elements alice has 
                  and b is number of elements bob has , 


                  now alice wants to maximize the score and bob wants to maximize it , 
                  
                  give the optimal score , if both play optimally 


          
      



*/

// Small Observatins
/*

      n is very small , 6 and t is 10^3 
      it means we can do n^2 for all the test cases . right ? 

      now focus on how , (a-b) is maximized , when  a is max and b is min 

      for each move , one of the player looses all the elements of i 
      , if i have 1 2 3 , then ill try to choose largest of it , 
      like choosing 3 , ill get , 1 2 2 , 

      but if i choose 1 , it is a loss for me , like i wil get 
      0 2 3 


      what is the optimal play for a player ? 
      ki samne wale ka jade nuksaan hoye , to mai samne wale ka 
      max element delet karne ki koshish karunga ? 
      ye phir apna max element bchaye ? 

      agar currect time t0 me , mera max uske max se chhota hai 
      to mai uska max uda dunga aur wo agle round me mera max udayega 

      agar current time me mera max uske max se bda hai to mai 
      apna max bachaunga , aur wo agle round me mera max nhi udapayega 



*/
//Your attacks
/*

      agar mere ko apna max bchana hai , aur mere pass mutiple max hai to mai wo max choose 
      karunga jisme samne wale ka maximum element jaye 

      isi tarah agar mujhe samne wale ka max udana hai 
      wo mai wo max udaunga jisme mera element max hai, if multiple max are there 



*/
// Hints From Code 
/*  

    is there any way to optimze my intution ? 



*/
int max_elem(vector<int>a,vector<bool>visited){
  int n=a.size();
  int mx=0;
  for(int i=0;i<n;i++){
    if(!visited[i]&&mx<a[i])mx=a[i];
  }
  return mx;
}
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n;cin>>n;
   vi a(n),b(n);
   invec(a);
   invec(b);
  //  int alice=1;
  //  int A=0 ,B=0;
  //  vector<bool>visited(n,false);
  //  for(int k=1;k<=n;k++){
  //   if(alice){
  //     int ma=max_elem(a,visited);
  //     int mb=max_elem(b,visited);
  //     if(ma>=mb){
  //       int idx=-1;
  //       int val=-1;
  //       for(int i=0;i<n;i++){
  //         if(!visited[i]&&ma==a[i]){
  //           if(val<b[i]){
  //             val=b[i];
  //             idx=i;
  //           }
  //         }
  //       }
  //       A+=ma-1;
  //       visited[idx]=true;
  //     }
  //     else {
  //       int idx=-1;
  //       int val=-11;
  //       for(int i=0 ;i<n ;i++){
  //         if(!visited[i]&&mb==b[i]){
  //           if(val<a[i]){
  //             val=a[i];
  //             idx=i;
  //           }
  //         }
  //       }
  //       A+=val-1;
  //       visited[idx]=true;
  //     }

  //   }
  //   else {
  //    int ma=max_elem(a,visited);
  //     int mb=max_elem(b,visited);
  //     if(mb>=ma){
  //       int idx=-1;
  //       int val=-1;
  //       for(int i=0;i<n;i++){
  //         if(!visited[i]&&mb==b[i]){
  //           if(val<a[i]){
  //             val=a[i];
  //             idx=i;
  //           }
  //         }
  //       }
  //       B+=mb-1;
  //       visited[idx]=true;
  //     }
  //     else {
  //       int idx=-1;
  //       int val=-11;
  //       for(int i=0 ;i<n ;i++){
  //         if(!visited[i]&&ma==a[i]){
  //           if(val<b[i]){
  //             val=b[i];
  //             idx=i;
  //           }
  //         }
  //       }
  //       B+=val-1;
  //       visited[idx]=true;
  //     }

  //   }
  //   alice=1-alice;
  //  }
  //  cout<<A-B<<endl;
  //code by gemini ;(
  vector<pair<int,int>>t;
  for(int i=0;i<n;i++){
    t.pb({a[i]+b[i],i});
  }
  sort(all(t));
  reverse(all(t));
  int score=0;
  for(int i=0;i<n;i++){
    int idx=t[i].ss;
    if(i%2==0){
      score+=(a[idx]-1);
    }
    else score-=(b[idx]-1);
  }
  cout<<score<<endl;
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