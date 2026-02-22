#include <bits/stdc++.h>
using namespace std;
//code by gpt
#define int long long
const int MOD = 998244353;
const int MAXN = 200005;

int fact[MAXN];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    fact[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int n = s.size();

        int deletions = 0;
        int ways = 1;

        for(int i = 0; i < n; ){
            int j = i;

           
            while(j < n && s[j] == s[i])
                j++;

            int len = j - i;

            if(len > 1){
                deletions += (len - 1);
                ways = (ways * len) % MOD;
            }

            i = j;
        }

       
        ways = (ways * fact[deletions]) % MOD;

        cout << deletions << " " << ways << "\n";
    }

    return 0;
}
