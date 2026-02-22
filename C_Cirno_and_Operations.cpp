#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
*/
// Problem Statement

//Question aasan hi hota hai bass uska ishara samajha 

/*
ek sequence di gayi hai a of length n , you can perform either of the following operation any number of time unless the current length of a is 1;
array me negative elementes bhi ho sakte hai 

operation : 
either reverse the sequence 
of replace the sequence with the difference sequence 

attacks: 
so mujhe array ko chhota  karna hai , to ek baat to fix hai ki mujhe 2nd operation atleast n-1 baar ko karni hi hogi ab baat ye hai ki
reverse karne se fayda kaise aa rha hai , 
kya mujhe baar baar new array form karna padega ? 




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
 
 long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r; 

    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - r + i) / i;
    }
    return ans;
}
void Chal_Ja_Plz(){
   int n;cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
  int ans =-1e18;
  int m=n;
  for(int i=0;i<m;i++){
    int sum=accumulate(arr.begin(),arr.begin()+n,0LL);
    if(i==0)ans=max(sum,ans);
    else ans=max({ans,sum,-sum});
    for(int i=0;i<n-1;i++)arr[i]=arr[i+1]-arr[i];
    n--;
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