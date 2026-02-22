#include <bits/stdc++.h>
using namespace std;
#define int long long 
// ------------------- Typedefs -------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// ------------------- Macros ---------------------
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

// ------------------- Constants ------------------
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// ------------------- Debugger -------------------
#ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ", _print(x)
#else
    #define debug(x...)
#endif


int merge(int i , int mid , int j, vector<int>&a){
    int n1=mid+1-i, n2=j-mid;
    vector<int>l(n1);
    int cnt=0;
    vector<int>r(n2);
    for(int k=0;k<n1;k++)l[k]=a[i+k];
    for(int k=0;k<n2;k++)r[k]=a[mid+1+k];
    int left=0;
    int right=0;
    while(left<n1&&right<n2){
        if(l[left]<=r[right]){
            a[i++]=l[left++];
        }
        else{
            a[i++]=r[right++];
            cnt+=n1-left;
        }
    }
    while(left<n1){a[i++]=l[left++];}
    while(right<n2)a[i++]=r[right++];
    return cnt;
}
int mergesort(int i, int j, vector<int>&a){
    int cnt=0;
    if(j>i){
        int mid =i+(j-i)/2;
        cnt+=mergesort(i, mid, a);
        cnt+=mergesort(mid+1,j, a);
        cnt+=merge(i, mid , j , a);
    }
    return cnt;
}
// ------------------- Solve Function -------------
void solve() {
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++)cin>>a[i];
  cout<< mergesort(0,n-1,a)<<endl;
    

}

// ------------------- Main Function --------------
signed main() {
    ios_base::sync_with_stdio(false);

    // freopen("bcount.in", "r", stdin);  for ucaso problems , put the name of the .in which is given 
   // freopen("bcount.out", "w", stdout);
  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);     // for local input
    freopen("output.txt", "w", stdout);   // for local output
    freopen("error.txt", "w", stderr);    // for debug output
#endif
    cin.tie(NULL);

    int t = 1;
    cin >> t;  // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
