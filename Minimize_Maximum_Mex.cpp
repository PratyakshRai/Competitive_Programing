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
 int minny;
int mex (vector<int>&a,int n){
  vector<int>store(n,-1);
  for(int i=0;i<n;i++){
    store[a[i]]++;

  }
  int mn=0;
  for(int i=0;i<n;i++){
    if(store[i]==-1){mn=i;return mn;}
  }
  return n;
}

void dp(int i, vector<int>&a , vector<int>&b,int n,int size){
  if(i>n)return ;
 
  
   minny=max(minny,min(mex(a,size),mex(b,size)));
  dp(i+1,a,b,n,size);
  swap(a[i],b[i]);
  dp(i+1,a,b,n,size);
  swap(a[i],b[i]);
  return; 
}
// ------------------- Solve Function -------------
void solve() {
   int n;
   cin>>n;
  minny=0;
   vector<int>a(n) ,b(n);
   for(int i =0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++)cin>>b[i];
   if(max(mex(a,size),mex(b,size))==0){
    cout<<0<<endl;
    return; 
   }
   dp(0,a,b,n-1,n);
   cout<<minny<<endl;
   return;


    

}

// ------------------- Main Function --------------
int main() {
    ios_base::sync_with_stdio(false);
  
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
