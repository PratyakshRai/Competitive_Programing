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
     get ready with prefix sum 
     first L and lastest R ko phale hi jod ke rakhlo 
     phir latest L aur 
    */
    // Hints From Code 
    /*  
     
    */
    void Chal_Ja_Plz(){
       int n;cin>>n;
       vi arr(n);
       for(int &i:arr)cin>>i;
       string s ;cin>>s;
       
       vi pre(n+1);
       for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+arr[i];
       }
       int ans=0;
       int l=0,r=n-1;
       while(r>l){
        while(l<n&&s[l]=='R')l++;
        while(r>=0&&s[r]=='L')r--;
        if(l<r){
          ans+=pre[r+1]-pre[l];
        }
        l++;
        r--;
     
       }
       cout<<ans<<endl;
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

