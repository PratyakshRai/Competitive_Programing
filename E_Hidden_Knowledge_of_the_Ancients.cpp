#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countAtMostK_withMaxLen(const vector<int>& a, int k, int maxLen) {
    if (maxLen <= 0) return 0;
    int n = a.size();
    unordered_map<int,int> freq;
    int left = 0;
    ll ans = 0;

    for (int right = 0; right < n; right++) {
        freq[a[right]]++;

        while ((int)freq.size() > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) freq.erase(a[left]);
            left++;
        }

       
        int maxStart = max(left, right - maxLen + 1);
        ans += (right - maxStart + 1);
    }
    return ans;
}

ll countAtMostK(const vector<int>& a, int k, int L, int R) {
    return countAtMostK_withMaxLen(a, k, R) - countAtMostK_withMaxLen(a, k, L-1);
}

ll countExactlyK(const vector<int>& a, int k, int L, int R) {
    return countAtMostK(a, k, L, R) - countAtMostK(a, k-1, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, L, R;
        cin >> n >> k >> L >> R;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << countExactlyK(a, k, L, R) << "\n";
    }

    return 0;
}
