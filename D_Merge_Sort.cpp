#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
int callsUsed = 0;

// Function to recursively build the permutation
void build(int l, int r) {
    if (callsUsed >= k) return; // Stop if we have already reached k calls
    callsUsed++;
    
    if (r - l <= 1) return;     // Single element segment is already sorted
    if (callsUsed == k) return; // Stop further recursion if exactly k calls reached

    int mid = l + (r - l) / 2;

    // Swap halves to make segment unsorted
    int len = min(mid - l, r - mid); // Ensure no overlap
    for (int i = 0; i < len; i++) {
        swap(a[l + i], a[mid + i]);
    }

    // Recurse on the left and right halves
    build(l, mid);
    build(mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    // Check impossible cases
    if (k % 2 == 0 || k > 2 * n - 1) {
        cout << -1 << "\n";
        return 0;
    }

    // Initialize permutation 1..n
    a.resize(n);
    iota(a.begin(), a.end(), 1);

    // Build the required permutation
    build(0, n);

    // Output the permutation
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}
