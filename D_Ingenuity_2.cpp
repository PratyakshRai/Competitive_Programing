/*
Author: Pratyaksh Rai
Date: 2026-03-06
Time: 12:39:52
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

        we have some sets of instruction and there are two rovers 
        we have to distributes the instruction to both the rovers in such 
        a way that they both ends up at the same location 
        ? 

        how they actually move ? 
        like one unit in either direction 
        do it by axis wise 
        do it for one axis , then for other . right? 

          lets take x axis : 

          so what we have to do , is to decide some point x 
          so that 
                    we can make both rover to reach that point x 
                    how to do that ?  
                    
                    so what we can do is to distribute 
                    the number of w e things 
                    like 
                          if there is even no of W or e only (w w or e e e e)
                          then we can equally distribute them to the rover 
                          if there is only odd no of W or E ie(w w w or e e e e)
                          then its impossible to do so 
                          if both are present in the same quantity
                          ie some of both is zero ie(w w w e e e ), then we will
                          give all to any one of the rover 
                          if some are of different quantity
                                then what to do ? 
                                                  
                                  1.(odd,even) (w w w e e) , 
                                  2.(even,even) (w w  , e e e e)
                                  if any one is odd (except both are equal) we cant do 
                                  anything 
                                  otherwise , we will distribute all of them equally 
                                  right ? length / 2 for each of them , right ? 

                            

*/
//Your attacks
/*
      if some of all the points is zero , then we can say , we will 
      apply all those in one rover and the total displacement will become zero 
      so both will be at the same point (0,0)

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n;cin>>n;
vector<int>a(4);
string s;cin>>s;
for(int i=0;i<n;i++){
  if(s[i]=='E')a[0]++;
  if(s[i]=='W')a[1]++;
  if(s[i]=='N')a[2]++;
  if(s[i]=='S')a[3]++;
}

if(abs(a[0]-a[1])%2||abs(a[2]-a[3])%2){
  NO;return;
}

 string ans = "";

    int tE = 0, tW = 0, tN = 1, tS = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'E') {
            ans += (tE ? 'H' : 'R');
            tE ^= 1; 
        } else if (s[i] == 'W') {
            ans += (tW ? 'H' : 'R');
            tW ^= 1;
        } else if (s[i] == 'N') {
            ans += (tN ? 'H' : 'R');
            tN ^= 1;
        } else if (s[i] == 'S') {
            ans += (tS ? 'H' : 'R');
            tS ^= 1;
        }
    }

  
   

 if(count(ans.begin(),ans.end(),'R')==0 || count(ans.begin(),ans.end(),'H')==0){
        cout<<"NO\n";
        return;
    }
cout<<ans<<endl;;

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