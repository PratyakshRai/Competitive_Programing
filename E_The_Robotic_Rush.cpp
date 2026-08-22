/*
Author: Pratyaksh Rai
Date: 2026-03-31
Time: 22:37:58
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


    there exits an infinitely long number line 
    there are n robots and m spikes 
    each located at  a specific point 

    ai for robot 
    bi for spikes 

    robot touches spike it dies 

    k instructions are transmitted , either move left or right 

    how many robots are still alive after first i instructions have been processed 

    har ek robot ke left wala distance aur right wala distance nikal liya 

    the thing is marne ke baad  uska khel khatam bhale hi aage jake 
    wapas se cheeje uske conditions ke andar hi kyu na ho 
    kitne log mare gye ye to nikal lunga , par kyuki age jake RRR se LLL ho rha hai 

    ab mare hue wapas thodi na ayenge ;)

    how to deal with those things ? 

    ab har ek point par , sabse left me kitna gya tha , aur sabse rigth me kitna gya tha wo nikal liya 

    ab har robot ko pakado , aur uske left distance ko search kro , aur right distance ko 
    search kro 
    aur undono ke minimum wale index par 1 likhdo 

    phir end me prefix sum ;')

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
/*
There is always a simpler solution for the question 
*/
   int n,m,k;cin>>n>>m>>k;
   vi a(n),b(m);
   invec(a);
   invec(b);
   string s;cin>>s;
    sort(all(b));
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        if(b[0]<a[i]){
            int left=a[i]-(*(lower_bound(b.begin(),b.end(),a[i])-1));
            mp[-left].pb(i);
        }
        if(b[m-1]>a[i]){
            int right=(*upper_bound(b.begin(),b.end(),a[i])-a[i]);
            mp[right].pb(i);
        }
    }
    int cur=0;
    int alive =n;
    vector<bool>dead(n,false);
    for(auto ch:s){
        if(ch=='R')cur++;
        else cur--;
        for(int i:mp[cur]){
            if(dead[i])continue;
            dead[i]=true;
            alive--;
        }
        mp[cur].clear();
        cout<<alive<<" ";
    }
    cout<<endl;;
    
  
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