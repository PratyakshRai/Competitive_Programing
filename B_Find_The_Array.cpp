/*
Author: Pratyaksh Rai
Date: 2026-03-23
Time: 19:21:18
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

      an array is given ,  S is the sum of all the elements of that array 

      let b is the array to be formed 

      for every adjacent pair of array b , 
      either bi divides bi+1 or bi+1 divides bi 
      or both , (both means numbers are same , like 5, 5)

      also 2*(summation of abs(ai-bi))<=s


*/

// Small Observatins
/*  

    it is mentioned that atleast one beatuful pair is given 

    how to find that array  ? 
     


*/
//Your attacks
/*

    can i take alt ones ? 
    no i cant , we have to make 2*(summation typo thing )

      what is even this function represents (summation of abs(ai-bi)) 
      how to minimize this function ? 

      if i take the median , then it is the minimum value ? right 


*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
int n;
        cin >> n;

        vector<long long> a(n);
        for(auto &x : a) cin >> x;

        long long S = 0;
        for(auto x : a) S += x;

        
        long long cur[2] = {0, 0};

        for(int i = 0; i < n; i++){
            cur[i % 2] += (a[i] - 1);
        }

        for(int j = 0; j < 2; j++){
            if(2 * cur[j] > S) continue;

            for(int i = 0; i < n; i++){
                if(i % 2 == j){
                    a[i] = 1;
                }
            }
            break;
        }

        for(auto x : a) cout << x << " ";
        cout << "\n";
// int n;cin>>n;
// vi a(n);
// invec(a)
// int sum =accumulate(a.begin(),a.end(),0LL);
// int c=sum/(2*n);
// for(int i=0;i<n;i++)cout<<c<<" ";
// cout<<endl;
// sort(a.begin(), a.end());

// int median = (a[(n+1)/2]+a[n/2])/2;
// if(n&1){
//   median=a[n/2];
// }
// else {
//   median =(a[n/2 -1]+a[n/2])/2;
// }
// for(int i=0;i<n;i++)cout<<median<<" ";
// cout<<endl;
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