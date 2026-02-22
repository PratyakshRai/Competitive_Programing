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

// ------------------- Solve Function -------------
void solve() {
    cout<<"50 50\n";
    ll cnt [4];
    vector<vector<int>>mat(50 , vector<int>(50));
    cin>>cnt[0]>>cnt[1]>>cnt[2]>>cnt[3];
    --cnt[0];
    --cnt[1];
    string order ="BCD";
    for(ll i=0;i<25;i++){
      for(ll j=0;j<50;j++){
        mat[i][j]='A';
        if(i%2==1&&j%2==1){
          for(char c:order){
            if(cnt[c-'A']>0){
              --cnt[c-'A'];
              mat[i][j]=c;
              break;
            }
          }
        }
      }

    }
    order="ACD";
    for(ll i =25;i<50;i++){
      for(ll j=0;j< 50 ;j++){
        mat[i][j]='B';
        if(i%2==0&&j%2==0){
          for(char c: order ){
            if(cnt[c-'A']>0){
              --cnt[c-'A'];
              mat[i][j]=c;
              break;
            }
          }
        }
      }
    }
for(ll i =0;i<50;i++){
  for(ll j=0;j<50;j++){
    cout<<mat[i][j];
  }
  cout<<"\n";
}
return ;
    

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
    // cin >> t;  // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
