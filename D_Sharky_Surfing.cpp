/*
Author: Pratyaksh Rai
Date: 2026-02-05
Time: 09:59:14
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
initial jmp=1;
    har ek interval per power dicide kar lenge like isko cross karne ke liye minimum kina power chahiye , aur ek set bna lenge phir us set se sabse bda powerup uthayeinge

    there is no pweup between the herdels 
*/
//Your attacks
/*

*/
// Hints From Code 
/*  

*/
void Chal_Ja_Plz(){
/*
Always try to optimize your approach
*/
   int n , m, l;cin>>n>>m>>l;
   vector<pair<int,int>>hurdel(n);
   for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    hurdel[i]={x,y};
   }
   map<int,int>mp;
   vector<pair<int,int>>power(m);
   for(int i=0;i<m;i++){
    int x,y;cin>>x>>y;
    mp[x]+=y;
    power[i]={x,y};
   }
   sort(all(power));
sort(all(hurdel));
int r=hurdel[n-1].ss;
   int jmp=1;
   multiset<int>st;
   int k=0;
   int cnt=0;
   int p=0;
   for(int i=0;i<n;i++){
    
//     auto it = mp.find(i);
// if (it != mp.end()) {
//     st.insert(it->second);
//     mp.erase(it);  
// }

    // if(mp.find(i)!=mp.end()){
    //   st.insert(mp[i]);
    // }
    int start=hurdel[i].ff;
    int end=hurdel[i].ss;
      int distance=hurdel[i].ss-hurdel[i].ff+2;

while(k < m && power[k].ff<start) {
    st.insert(power[k].ss);
    k++;
}

 while(!st.empty()&&jmp<distance){
        auto add=prev(st.end());
        int A=*add;
        jmp+=A;
        st.erase(add);
        cnt++;
      

      }
      if(jmp<distance){
        cout<<"-1\n";return;
      }







// while(k < m && power[k].ff == i) {
//     st.insert(power[k].ss);
//     k++;
// }
//     if(p<n&&i==hurdel[p].ff){
//       int distance=hurdel[p].ss-hurdel[p].ff+2;
//       p++;
//       if(jmp>=distance)continue;
//       while(!st.empty()&&jmp<distance){
//         auto add=prev(st.end());
//         int A=*add;
//         jmp+=A;
//         st.erase(add);
//         cnt++;
      

//       }
//       if(jmp<distance){
//         cout<<"-1\n";return;
//       }
    // }
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