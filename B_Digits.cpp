 #include <bits/stdc++.h>
using namespace std;

long long fact(long long x) {
    long long ans = 1;
    for (long long i = 1; i <= x; i++) ans *= i;
    return ans;
}

int modString(const string &s, int mod) {
    long long res = 0;
    for (char c : s) {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        n = min(n, 7LL);
        long long f = fact(n);

        string ks = to_string(k);
        string big = "";
        big.reserve(ks.size() * f);

        for (long long i = 0; i < f; i++) {
            big += ks;
        }

        for (int d = 1; d <= 9; d += 2) {
            if (modString(big, d) == 0) {
                cout << d << " ";
            }
        }
        cout << "\n";
    }
}
