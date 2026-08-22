#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    // Input data
    vector<string> vm_names = {"VM1", "VM2", "VM3", "VM4", "VM5", "VM6", "VM7", "VM8"};
    vector<int> memory = {4, 2, 6, 5, 7, 3, 1, 8};
    vector<int> revenue = {12, 10, 18, 15, 22, 11, 5, 25};
    int max_memory = 18;
    int n = memory.size();

    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(max_memory + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= max_memory; w++) {
            if (memory[i - 1] <= w) {
                dp[i][w] = max(revenue[i - 1] + dp[i - 1][w - memory[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Traceback to find selected VMs
    int res = dp[n][max_memory];
    int w = max_memory;
    vector<string> selected_vms;
    int mem_used = 0;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            selected_vms.push_back(vm_names[i - 1]);
            mem_used += memory[i - 1];
            res -= revenue[i - 1];
            w -= memory[i - 1];
        }
    }
    
    // Reverse to display in ascending order
    reverse(selected_vms.begin(), selected_vms.end());

    // Display Input
    cout << "--- Budget-Constrained Cloud Resource Allocation ---\n\n";
    cout << "Available Memory: " << max_memory << " GB\n\n";
    cout << "VM Name\tMemory (GB)\tRevenue (Lakhs)\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << vm_names[i] << "\t" << memory[i] << "\t\t" << revenue[i] << "\n";
    }
    cout << "\n";

    // Display DP Table
    cout << "Dynamic Programming Table:\n";
    cout << "W=   ";
    for (int j = 0; j <= max_memory; j++) cout << setw(3) << j << " ";
    cout << "\n--------------------------------------------------------------\n";
    for (int i = 0; i <= n; i++) {
        cout << "i=" << i << " |";
        for (int j = 0; j <= max_memory; j++) {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Display Results
    cout << "Maximum Expected Revenue: " << dp[n][max_memory] << " Lakhs\n";
    cout << "Selected Virtual Machines: ";
    for (size_t i = 0; i < selected_vms.size(); i++) {
        cout << selected_vms[i] << (i == selected_vms.size() - 1 ? "" : ", ");
    }
    cout << "\n";
    cout << "Total Memory Utilized: " << mem_used << " GB\n";
    cout << "Unused Memory: " << (max_memory - mem_used) << " GB\n";

    return 0;
}