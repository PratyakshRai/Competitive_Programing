#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// custom splitmix64 hash to avoid adversarial collisions
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return (size_t)splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n, x;
    if (!(cin >> n >> x)) return;
    vector<int64> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    unordered_map<int64, int64, custom_hash> freq;
    freq.reserve((size_t)(n * 1.3) + 10);      // avoid rehashing
    freq.max_load_factor(0.7f);

    freq[0] = 1;
    int64 current = 0;
    int64 cnt = 0;
    for (int i = 0; i < n; ++i) {
        current += arr[i];
        int64 needed = current - x;
        auto it = freq.find(needed);
        if (it != freq.end()) cnt += it->second;
        ++freq[current];
    }
    cout << cnt << '\n';
}

int main() {
    solve();
    return 0;
}
