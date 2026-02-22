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
vector<string>storage;
void dp(string test, long long  n4, long long  n7, long long  maxsize,vector<string>&storage){
  if(test.size()==maxsize){
    if(n4==n7)storage.push_back(test);

    return ;
  }
  dp(test+'4',n4+1,n7,maxsize,storage);
  dp(test+'7',n4,n7+1,maxsize,storage);
  return ;
}
// ------------------- Solve Function -------------
void solve() {
   string s;
   cin>>s;
   long long  n=s.size();
   if(n&1)n++;
    long long  n4=0,n7=0;
    string test="";
    for(int i=n;;i+=2){
      storage.clear();
    dp(test,n4,n7,i,storage);
    for(auto it : storage){
      if(stoll(it)>=stoll(s)){cout<<it;return ;}
    }}

    

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
    // cin >> t;  // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
