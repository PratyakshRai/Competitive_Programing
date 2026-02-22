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
bool dp(int i, int target, vector<int>&bars){
  if(i<0)return false;
  if(i==0)return bars[0]==target;
  if(target==0)return true;
  bool take =false;
  if(target>=bars[i]){
   take =dp(i-1,target-bars[i],bars);}//target-bars[i]negative nhi ho to aur optimized ho sakta hai ;)
  bool nottake=dp(i-1,target,bars);
  return take|nottake;
}
// ------------------- Solve Function -------------
void solve() {
  int target,n;
  cin>>target>>n;
  vector<int>bars(n);
  for(int i=0;i<n;i++){
    cin>>bars[i];
  }
  if(dp(n-1,target, bars))cout<<"YES";
  else cout<<"NO";
  cout<<endl;
  return ;
  

    

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
