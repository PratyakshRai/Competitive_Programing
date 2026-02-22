#include<bits/stdc++.h>
using namespace std;
#define int long long
 
// Problem Statement
/*
hamare pass ek interger hai x aur ek function hai f(x);
hame n hi diya jayega , aur ye batana hai ki ,
x^f(x)=n hoga chahiye, f(x) jo hai ho x ka reverse binarey representation hai ,jaise    10110100 ka hoga 00101101

*/
 
// Small Observatins
/*
if n==0 to koi bhi palindrome lelo 


*/
 
 
//Your attacks
/*
 
*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*
these two function :

int msb = 63-__builtin_clzll(n);
int lsb=__builtin_ctzll(n);



*/

bool checkpal(int k,int b, int n) {
    int i = b, j = k;
    while (i <= j) {
       int left = (n >> j) & 1;
int right = (n >> i) & 1;
   if((i==j)&&(left==1))return false;
        if (left != right) return false;
        i++; j--;
    }

    return true;
}

void Chal_Ja_Plz() {
    int n; cin >> n;
    if(n==0){cout<<"YES\n";return ;}
    int msb = 63-__builtin_clzll(n);
    

    int lsb=__builtin_ctzll(n);
    if(checkpal(msb,lsb,n)){
      cout<<"YES ";
    }else cout<<"NO ";
  cout<<"\n";

  }
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}