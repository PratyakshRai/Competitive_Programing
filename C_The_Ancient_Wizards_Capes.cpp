

#include <bits/stdc++.h>
using namespace std;
#define int long long

void Chal_Ja_Plz() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

  
    for (int first_x = 0; first_x <= 1; first_x++) {
        vector<int> x(n);
        x[0] = first_x;
        bool possible = true;
        int current_sum = x[0];

       
        for (int i = 0; i < n - 1; i++) {
          
            x[i + 1] = a[i + 1] - a[i] + 1 - x[i];
            
       
            if (x[i + 1] < 0 || x[i + 1] > 1) {
                possible = false;
                break;
            }
            current_sum += x[i + 1];
        }

        
        if (possible) {
            int required_sum = n + x[0] - a[0];
            if (current_sum == required_sum) {
                ans++;
            }
        }
    }

    
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;
    while (t--) {
        Chal_Ja_Plz();
    }
    return 0;
}