#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int t;
    cin>>t;
    while(t--){
        string s;
    cin>>s;
    int n=s.size();
    string ans="";
    int i=0;
 while (i<n) {
            if (i+1<n&&s[i]=='s'&&s[i+1]=='c') {
                ans+='g';i+=2;
              
            } else {
                ans += s[i];
                i++;
            }
        }
    cout<<ans<<"\n";

}
    return 0;
}
