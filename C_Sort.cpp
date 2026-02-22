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
 
 */
 // Hints From Code 
 /*  
 
 */
 void Chal_Ja_Plz(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>pre1(n+1,vector<int>(26,0));
    vector<vector<int>>pre2(n+1,vector<int>(26,0));
    for(int i =1;i<=n;i++){
      char ch;
      cin>>ch;
      pre1[i][ch-'a']++;
      for(int j =0;j<26;j++){
        pre1[i][j]+=pre1[i-1][j];
      }
    }
     for(int i =1;i<=n;i++){
      char ch;
      cin>>ch;
      pre2[i][ch-'a']++;
      for(int j =0;j<26;j++){
        pre2[i][j]+=pre2[i-1][j];
      }
    }
    while(q--){
      int l,r;
      cin>>l>>r;
      int diff=0;
      for(int c=0;c<26;c++){
        int v1=pre1[r][c]-pre1[l-1][c];
        int v2=pre2[r][c]-pre2[l-1][c];
        diff+=max(0*l,v1-v2);
      }
      cout<<diff<<endl;
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