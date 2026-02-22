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
     
    bool can(ll mid, vector<ll>&a  , vector<ll>&b, ll n, ll k){
     __int128 kk=k;
     
      for(ll i=0;i<n;i++){
        __int128 needed=(__int128)a[i]*mid;
        if(needed>b[i]){
          kk-=(needed-b[i]);
        }
        if(kk<0)return false;
      }
      return true;
    }
    // ------------------- Solve Function -------------
    void solve() {
        ll n, k;
        cin>>n>>k;
        vector<ll>a(n),b(n);
        for(int i =0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        ll low=0;
        ll high=2e12;
        // for(int i=0;i<n;i++){
        //   high=max(high,( b[i]+k)/a[i]);
        // }
        while(low<=high){
          ll mid=low+(high-low)/2;
          if(can(mid , a , b, n, k)){
            low=mid+1;
          }
          else high=mid-1;
        }
        
        cout<<high;
     
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