#include <bits/stdc++.h>
using namespace std;

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

void _print(int x) { cerr << x << '\n'; }
void _print(long x) { cerr << x << '\n'; }
void _print(ll x) { cerr << x << '\n'; }
void _print(unsigned x) { cerr << x << '\n'; }
void _print(unsigned long x) { cerr << x << '\n'; }
void _print(unsigned long long x) { cerr << x << '\n'; }
void _print(float x) { cerr << x << '\n'; }
void _print(double x) { cerr << x << '\n'; }
void _print(long double x) { cerr << x << '\n'; }
void _print(char x) { cerr << '\'' << x << '\'' << '\n'; }
void _print(const char *x) { cerr << '\"' << x << '\"' << '\n'; }
void _print(const string &x) { cerr << '\"' << x << '\"' << '\n'; }
void _print(bool x) { cerr << (x ? "true" : "false") << '\n'; }

template <typename T, typename V> void _print(const pair<T, V> &x) {
    cerr << '{'; _print(x.first); cerr << ','; _print(x.second); cerr << '}';
}
template <typename T> void _print(const T &x) {
    cerr << '{'; bool first = true;
    for (const auto &i : x) {
        if (!first) cerr << ", ";
        _print(i); first = false;
    }
    cerr << "}\n";
}
bool can(int x ,vector<int>&a,int sum,int n){
  double hafl=(sum+x)/(2.0*n);
  int cnt=0;
  for(int v:a){
    if(v<hafl)cnt++;
  }
  return cnt>n/2;
}
// ------------------- Solve Function -------------
void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    int sum=0;int maxy=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      sum+=arr[i];
      maxy=max(maxy,arr[i]);
    }
if(n==1||n==2){
  cout<<-1<<"\n";
  return;
}

if(can(0,arr,sum,n)){
cout<<0<<"\n";
return;
}
int low=0;
int high=2e14;
while(low<=high){
  int mid=low+(high-low)/2;
  if(can(mid,arr,sum,n)){
    high=mid-1;
  }else {
    low=mid+1;
  }
}
cout<<low<<endl;

    // int high=n*maxy;
    // int low =0;
    // double avg=1.0*sum/n;
    // while(low<=high){
    //   int mid=low+(high-low)/2;
    //   int temp=sum;
    //   temp+=mid;
    //   double tempavg=(1.0*temp)/n;
    //   double check=tempavg/2.0;
    //   int cnt=0;
    //   for(int i=0;i<n;i++){
    //     if(check>arr[i])cnt++;
    //   }
    //   if(cnt<=n/2){
    //     low=mid+1;
    //   }
    //   else high=mid-1;

    // }

    // cout<<low<<endl;

}

// ------------------- Main Function --------------
int main() {
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
