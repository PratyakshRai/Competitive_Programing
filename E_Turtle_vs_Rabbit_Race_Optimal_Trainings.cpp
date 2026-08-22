#include <bits/stdc++.h>
using namespace std;

#define int             long long
#define pb              push_back
#define all(x)          (x).begin(), (x).end()
#define endl            '\n'
#define vi              vector<int>

int get_score(int u, int count) {
    if (count <= 0) return -2e18;
    int last_term = u - count + 1;
    return count * (u + last_term) / 2;
}
//code by gemini ;)

void Chal_Ja_Plz() {
    int n; 
    cin >> n;
    
    vi a(n + 1, 0);
    vi pref(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    
    int q;
    cin >> q;
    
    while(q--) {
        int l, u;
        cin >> l >> u;
        
        int target = pref[l - 1] + u;
        auto it = upper_bound(pref.begin() + l, pref.end(), target);
        
        int R1 = -1, R2 = -1;
        
        if(it != pref.end()) {
            R1 = it - pref.begin();
        }
        R2 = (it - pref.begin()) - 1;
        
        int best_r = l;
        int max_score = -2e18;
        
        if(R2 >= l && R2 <= n) {
            int count_sections = pref[R2] - pref[l - 1];
            int current_score = get_score(u, count_sections);
            if(current_score > max_score) {
                max_score = current_score;
                best_r = R2;
            }
        }
        
        if(R1 >= l && R1 <= n) {
            int count_sections = pref[R1] - pref[l - 1];
            int current_score = get_score(u, count_sections);
            if(current_score > max_score) { 
                max_score = current_score;
                best_r = R1;
            }
        }
        
        cout << best_r << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    
    return 0;
}