#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
//Ye Question kyu nhi ho paya && uska future solution kya rakhoge
/*
 
 
 
 
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
 int upperbnd(int target,vector<int>&b,int n){
  int low=0,high=n-1;
  //target<=upper
  while(low<=high){
    int mid=low+(high-low)/2;
    if(b[mid]>=target)high=mid-1;
    else low=mid+1;
    
  

  }
  if(low==n){
    return -1;
  }

      return b[low];
 }
 int lowerbnd(int target,vector<int>&b,int n ){
  int low=0,high=n-1;
  //lower<=target if target>=lower high=mid-1
   while(low<=high){
    int mid=low+(high-low)/2;
    if(b[mid]>target)high=mid-1;
    else low=mid+1;
  }
  if(high==-1)return -1;
 return b[high];
 }
 void Chal_Ja_Plz(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> b(m);
    for (int &i : b) cin >> i;
    sort(b.begin(), b.end());

    vector<int> arr(q);
    for (int &i : arr) cin >> i;

    for (int i = 0; i < q; i++) {
        int test = arr[i];
        int up = upperbnd(test, b, m);   // first >= test
        int low = lowerbnd(test, b, m);  // first >= test
    
        if(up==-1||low==-1){
          if(up==-1){
            cout<<n-low<<'\n';
          }
          else {
            cout<<up-1<<'\n';
          }
        }
        else cout<<(up-low)/2<<"\n";
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