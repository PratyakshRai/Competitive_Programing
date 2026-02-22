#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        int minFreq = INT_MAX, maxFreq = 0;
        for (int f : freq) {
            if (f > 0) {
                minFreq = min(minFreq, f);
                maxFreq = max(maxFreq, f);
            }
        }

        // Collect all characters with min and max frequency
        vector<char> minChars, maxChars;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == minFreq)
                minChars.push_back('a' + i);
            if (freq[i] == maxFreq)
                maxChars.push_back('a' + i);
        }

        char minChar = '?', maxChar = '?';

        // Choose valid pair such that minChar != maxChar
        for (char a : minChars) {
            for (char b : maxChars) {
                if (a != b) {
                    minChar = a;
                    maxChar = b;
                    break;
                }
            }
            if (minChar != '?') break;
        }

        // Edge case: if all chars have same frequency (e.g., "aabb")
        // Then just pick any two *different* characters from s
        if (minChar == '?' || maxChar == '?') {
            minChar = s[0];
            for (char c : s) {
                if (c != minChar) {
                    maxChar = c;
                    break;
                }
            }
            if (maxChar == '?')
                maxChar = minChar;
        }
        for (char &c : s) {
            if (c == minChar) {
                c = maxChar;
                break;
            }
        }

        cout << s << "\n";
    }
    return 0;
}
