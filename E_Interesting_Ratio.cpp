#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 too close isne kya kiya ki ek baar y ko fix kar rha hai loop ke jariye aur doosare se division se count kar rha hai ki kitne number hue
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

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
 
 
// Learn form question
/*



*/
 const int MAXN = 10000001;
bool prime[MAXN];

 
void Chal_Ja_Plz(){
   int n,ans=0;
   cin>>n;
   for(int i=2;i<=n;i++){
    if(prime[i])ans+=n/i;
   }
   cout<<ans<<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < MAXN; i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
	for (int i = 2; i * i < MAXN; i++) {
	    if (!prime[i]) continue;
	    for (int j = i * i; j < MAXN; j += i) 
            prime[j] = 0;
	}
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}