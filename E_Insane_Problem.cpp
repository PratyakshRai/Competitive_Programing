 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
  
  
  
 //Ye Question kyu nhi ho paya && uska future solution kya rakhoge
 /*
  
  
  
  
 */
 // Problem Statement
 
 //Question aasan hi hota hai bass uska ishara samajha 
 
 /*
 you are given five interger  k l r l r 
 you have to count the number of ordered pair  (x,y);

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
  
  
 // Learn form question
 /*
 
 
 
 */
  
  
 void Chal_Ja_Plz(){
    int k , l1, r1 , l2, r2 ;cin>>k>>l1>>r1>>l2>>r2;
    int kn=1,ans=0;
    for(int n=0;r2/kn>=l1;n++){
      ans+=max(0LL,min(r2/kn,r1)-max((l2-1)/kn+1,l1)+1LL);
  kn*=k;
    }
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