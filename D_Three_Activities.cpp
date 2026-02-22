/*
CODE BY CHAT GPT

Author: Pratyaksh Rai
Date: 2026-01-22
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n' 
#define vi vector<int>
#define ff first
#define ss second

void Chal_Ja_Plz() {
    int n; 
    cin >> n;

    // Use pair to store {value, original_index}
    vector<pair<int,int>> a, b, c;

    // Reading inputs
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back({x, i});
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.push_back({x, i});
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        c.push_back({x, i});
    }

    // Sort descending to get the best elements at the start
    // greater<>() works perfectly for pairs (sorts by value first)
    sort(all(a), greater<>());
    sort(all(b), greater<>());
    sort(all(c), greater<>());

    int ans = 0;
    
    // We only need to check the top 3 elements of each array.
    // 3*3*3 = 27 iterations (Constant time)
    int lim = 3; 
    
    // Safety check: if N is huge, this is fine. If N < 3, logic handles it naturally or problem guarantees N >= 3.
    // Since problem 1914D guarantees N >= 3, strictly using 3 is fine.
    
    for(int f = 0; f < lim; f++){
        for(int s = 0; s < lim; s++){
            for(int t = 0; t < lim; t++){
                
                // CRITICAL STEP: Ensure we pick 3 DISTINCT days (indices)
                if(a[f].ss != b[s].ss &&
                   a[f].ss != c[t].ss &&
                   b[s].ss != c[t].ss){
                    
                    int current_sum = a[f].ff + b[s].ff + c[t].ff;
                    ans = max(ans, current_sum);
                }
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    // Fast I/O is mandatory for N=10^5
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; 
    cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}