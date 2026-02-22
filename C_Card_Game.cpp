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

//Your attacks
/*
   1 aur n dono jiske pass rha wo winner 
   Alice:   
            if alice has 1 , 
                also he has n-1   
                  then if bob have only n no card he looses 
                  otherwise he will win 
            if bob has 1 ,
                 aur n-1 card jiska bhi hoga wo jeetega  

*/

void Chal_Ja_Plz(){
   int n;cin>>n;
   string s; cin>>s;
   if(s[0]==s[n-1]){
    if(s[0]=='A')cout<<"Alice\n";
    else cout<<"Bob\n";
    return;
   }
   vi alice, bob;
   for(int i=1;i<=n;i++){
    if(s[i-1]=='A')alice.pb(i);
    else bob.pb(i);
   }
   if(bob[0]==1){
    if(s[n-2]=='A')cout<<"Alice\n";
    else cout<<"Bob\n";
    return;
   }
   else {
    if(bob.size()==1)cout<<"Alice\n";
    else cout<<"Bob\n";
   }

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