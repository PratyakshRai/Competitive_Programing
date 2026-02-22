#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define endl '\n'

bool can_sell_all(int m, int x, int sum_a, int max_a) {
    // 1. One customer can't buy more than one of the same model
    if (m < max_a) return false;
    
    // 2. Total capacity check: m customers can buy at most m * x cars
    // Using __int128 or a division check to prevent overflow
    if (m == 0) return sum_a == 0;
    return (sum_a <= m * x);
}

void Chal_Ja_Plz() {
    int n, x; 
    cin >> n >> x;
    vi a(n);
    int sum_a = 0;
    int max_a = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
        max_a = max(max_a, a[i]);
    }

    int l = max_a; // Minimum must be at least the highest individual count
    int h = 2e14;  // Safe upper bound (sum_a is max 5e5 * 1e9)
    int ans = h;

    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(can_sell_all(mid, x, sum_a, max_a)) {
            ans = mid;    // This works! Let's try to find a smaller minimum
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) Chal_Ja_Plz();
    return 0;
}