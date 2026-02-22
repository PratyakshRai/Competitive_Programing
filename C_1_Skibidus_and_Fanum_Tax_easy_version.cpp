#include<bits/stdc++.h>
using namespace std;
#define int long long

void Chal_Ja_Plz(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), brr(m);
    for(int &i : arr) cin >> i;
    for(int &i : brr) cin >> i;
    
    sort(brr.begin(), brr.end());
    
    int previous = -2e18; // Very small number
    
    for(int i = 0; i < n; i++){
        int val1 = 2e18; // Represents keeping arr[i]
        int val2 = 2e18; // Represents swapping with brr[j] - arr[i]
        
        // Option 1: Keep the element as is
        if(arr[i] >= previous){
            val1 = arr[i];
        }
        
        // Option 2: Swap (Find smallest b[j] such that b[j] - arr[i] >= previous)
        // Equation: b[j] >= previous + arr[i]
        auto it = lower_bound(brr.begin(), brr.end(), previous + arr[i]);
        
        if(it != brr.end()){
            val2 = *it - arr[i];
        }
        
        // Choose the minimum valid option to make life easier for the next elements
        int chosen = min(val1, val2);
        
        if(chosen == 2e18){ // If neither was valid
            cout << "NO\n";
            return;
        }
        
        previous = chosen;
    }
    
    cout << "YES\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) Chal_Ja_Plz();
    return 0;
}