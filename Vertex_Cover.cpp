#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];

// DFS function to calculate distances from a given starting 'node'
void dfs(int node, int parent, int current_distance, vector<int>& dist_array) {
    dist_array[node] = current_distance;
    
    for (int child : adj[node]) {
        if (child != parent) {
            // Child ki distance parent se +1 hogi
            dfs(child, node, current_distance + 1, dist_array);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    // Read the N-1 edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Arrays to store distances
    vector<int> dist(n + 1, 0);  // Temporary array for DFS 1
    vector<int> distA(n + 1, 0); // Distances from Endpoint A
    vector<int> distB(n + 1, 0); // Distances from Endpoint B
    
    // ---------------------------------------------------------
    // STEP 1: DFS 1 - Find Endpoint A of the diameter
    // ---------------------------------------------------------
    // Start from an arbitrary node (Node 1)
    dfs(1, 0, 0, dist);
    
    int endpointA = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[endpointA]) {
            endpointA = i;
        }
    }
    
    // ---------------------------------------------------------
    // STEP 2: DFS 2 - Find Endpoint B & store distances from A
    // ---------------------------------------------------------
    // Now run DFS from endpointA and record distances in distA
    dfs(endpointA, 0, 0, distA);
    
    int endpointB = 1;
    for (int i = 1; i <= n; i++) {
        if (distA[i] > distA[endpointB]) {
            endpointB = i;
        }
    }
    
    // ---------------------------------------------------------
    // STEP 3: DFS 3 - Store distances from Endpoint B
    // ---------------------------------------------------------
    // Finally, run DFS from endpointB and record distances in distB
    dfs(endpointB, 0, 0, distB);
    
    // ---------------------------------------------------------
    // FINAL ANSWER: Maximum of distance from A or distance from B
    // ---------------------------------------------------------
    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O is crucial for CSES problems with large N (up to 2*10^5)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}