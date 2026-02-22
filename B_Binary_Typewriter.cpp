#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 good question , pahale hamne dekha ki kaise l r index ans par effect daal rhe hai phir clever tarike se ye dekha ki ans no of changes se kaise badal rha hai , l aur r ko swap karna hai to minimum no of exchange 3 hua iska matlab l-1 aur l me ek hua  , aur l se r ke beech me ek hua , aur r r+1 me ek hua , tak hame ye pta chalta hai ki l-1 !=l aur r !=r+1 , like isse reverse engeenering ki tarah bhi soocha ja sakta hai , like pahale mujhe ye eqality wali cheej soochni thi phir jake mera conclusion no of swap pe jata 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek binary string hai n length ki , aur ek typewritter hai jisme do hi button hai 0 aur 1 

pahale hamara haath 0 button pe hai starting se hi 


you can do some operation : 
press the current button of your fingure 
or just move to the other one 



the cost of binary string in defined as the minimum number of operation needed to type the entire string 


before typing the substring you can reverse atmost one substring 

*/
 
// Small Observatins
/*

hame ye observe karna hai ki reverse karne se string pe kya effect padta hai , like kaise fayda mill rha hai hame 

*/
 
 
//Your attacks
/*
theory : 
ham starting bit 0 le sakte hai 
0 [1 0 0]
0 [0 0 1]
1101 0100100110111 00
1110 0100100110111 00
1101 0100100011111 00
110{1 111}011001001{0 00}

kuch ayesa kro ki reverse karne ke baad lambi consecutive string bne

kya new string form karne ki jarurat bhi hai ? 

minimum ans to n jitna hoga , ab n me add kitna ho rha hai wo number of switches ya bolo a[i]!=a[i+1]pe depend kar rha hai 




so matlab interval ke border se matlab hai , 

l-1 l r r+1
l se r  tak reverse karna hai , to 
 
if l==r then nothing will happen 
else if l!=r then: 
aur agar l-1 r ke equal hua to ans--
ya agar r+1 l ke equal hua to ans-- 


*/
 
 
// Hints From Code 
/*  


 
*/
 
 
// Learn form question
/*



*/
 
 
void Chal_Ja_Plz(){
   int n ;cin>>n;
   string s ;cin>>s; 
   int ans=0;
  char prev='0';
   for(int i=0;i<n;i++){
    if(s[i]!=prev){
      ans++;
      prev=s[i];
    }
   }
   if(ans>=3){
    cout<<ans-2+n<<"\n";
   }
   else if(ans==2){
    cout<<ans-1+n<<"\n";
   }else cout<<ans+n<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}