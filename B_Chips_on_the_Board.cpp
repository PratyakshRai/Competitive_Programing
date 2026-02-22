    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
     
    // Problem Statement
    /*
    nxn board hai , A aur B number hai of size N
     
     
    tasks : 
    hame chips rakhne hai cells (i,j); par aur usse following condition satisfy hone chahiye sabhbi (i,j) ke liye : 
     
    kisi particular (i,j) ke liye atleast one chip ho same row or same column me  ya dono me , like atleast one chip hona chahiye yato same col me ho ya to same row me or either same i and same j ie us par hi rkha hai chip ko 
     
    the cost of putting a chip is ai+bj
     
     calculate the minimum cost 
     
     
    */
     
    // Small Observatins
    /*
     
      int mx = *max_element(v.begin(), v.end());
     
    */
     
     
    //Your attacks
    /*
    har row ko pakdenge aur minimum col select karenge
    ya har col ko pakdenge aur minimum row select karenge 
     
    to isse kya hoga , yato har row me ek hoga , yato kar col me ek hoga 
    phir ham in dono ko ek jagah store kardenge aur , har ek i aur j ke liye dekhenge ki minimum kinki wajah se aa rha hai 
     
     
    */
     
     
    // Hints From Code 
    /*  
     
     
     
    */
     
     
    // Learn form question
    /*
      int mx = *max_element(v.begin(), v.end());
     
     
    */
     
     
    void Chal_Ja_Plz(){
       int n;cin>>n;
       vector<int>a(n),b(n);
       for(int &i: a)cin>>i;
       for(int &i: b)cin>>i;
       int ma=*min_element(a.begin(),a.end());
       int mb=*min_element(b.begin(),b.end());
       int ans1=0,ans2=0;
       for(int i=0;i<n;i++){
        int row=a[i]+mb;
        int col=b[i]+ma;
        ans1+=row;
        ans2+=col;
     
       }
       int ans=min(ans1,ans2);
       cout<<ans<<"\n";
      }
     
    int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
     
        int t; cin >> t;
        while (t--) Chal_Ja_Plz();
        return 0;
    }