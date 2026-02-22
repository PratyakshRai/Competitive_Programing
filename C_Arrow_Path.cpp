#include <bits/stdc++.h>
 
using namespace std;
 
#define ll     long long
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
#define ff     first
#define ss     second
#define pb     push_back
 
 
int main()
{
    _test
    {
        int n;
        cin>>n;
 
        vector<string> s(2);
        cin>>s[0]>>s[1];
 
        vector<vector<int>> pos(2, vector<int> (n));
 
        pos[0][0] = 1;
 
        queue<pair<int, int>> qp;
 
        qp.push({0, 0});
 
        while(qp.size())
        {
            auto e = qp.front();
            int x = e.ff;
            int y = e.ss;
            qp.pop();
 
            if(x-1>=0)
            {
                if(s[x-1][y]=='>' && !pos[x-1][y+1])
                {
                    pos[x-1][y+1] = 1;
                    qp.push({x-1, y+1});
                }
            }
 
            if(x-1>=0)
            {
                if(s[x-1][y]=='<' && !pos[x-1][y-1])
                {
                    pos[x-1][y-1] = 1;
                    qp.push({x-1, y-1});
                }
            }
 
            if(x+1<=1)
            {
                if(s[x+1][y]=='>' && !pos[x+1][y+1])
                {
                    pos[x+1][y+1] = 1;
                    qp.push({x+1, y+1});
                }
            }
 
            if(x+1<=1)
            {
                if(s[x+1][y]=='<' && !pos[x+1][y-1])
                {
                    pos[x+1][y-1] = 1;
                    qp.push({x+1, y-1});
                }
            }
 
            if(y-1>=0)
            {
                if(s[x][y-1]=='<' && !pos[x][y-2])
                {
                    pos[x][y-2] = 1;
                    qp.push({x, y-2});
                }
            }
 
            if(y+1<n)
            {
                if(s[x][y+1]=='>' && !pos[x][y+2])
                {
                    pos[x][y+2] = 1;
                    qp.push({x, y+2});
                }
            }
        }
 
        if(pos[1][n-1])       cout<<"YES\n";
        else                  cout<<"NO\n";
    }
}