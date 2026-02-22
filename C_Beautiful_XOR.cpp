#include <iostream>

// Function to get the position of the most significant bit (MSB)
// (e.g., msb(10) = 3, msb(8) = 3, msb(7) = 2)
int get_msb_pos(long long n) {
    if (n == 0) {
        return -1; // No bits set
    }
    // 63 - (number of leading zeros) gives the 0-indexed MSB
    return 63 - __builtin_clzll(n);
}

void solve() {
    long long a, b;
    std::cin >> a >> b;

    if (a == b) {
        // Case 1: Already equal
        std::cout << "0\n\n";
    } else if (a > b) {
        // Case 2: a > b
        long long x = a ^ b;
        if (x <= a) {
            // 1-step solution
            std::cout << "1\n";
            std::cout << x << "\n";
        } else {
            // 2-step solution
            std::cout << "2\n";
            std::cout << b << " " << a << "\n";
        }
    } else {
        // Case 3: a < b
        int msb_a = get_msb_pos(a);
        int msb_b = get_msb_pos(b);

        if (msb_a < msb_b) {
            // Impossible to increase MSB
            std::cout << "-1\n";
        } else {
            // msb_a == msb_b, guaranteed 2-step solution
            int k = msb_a;
            // M = (1 << (k+1)) - 1
            // e.g., if k=3, M = (1<<4)-1 = 15 (binary 1111)
            long long M = (1LL << (k + 1)) - 1; 
            
            long long x1 = a ^ M;
            long long x2 = M ^ b;

            std::cout << "2\n";
            std::cout << x1 << " " << x2 << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}