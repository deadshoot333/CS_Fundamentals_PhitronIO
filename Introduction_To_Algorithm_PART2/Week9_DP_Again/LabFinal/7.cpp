#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int n, x;
map<int, int> dist;
bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int king = q.front();
        q.pop();
        string s = to_string(king);
        if (s.size() == n)
        {
            cout << dist[king] << "\n";
            return true;
        }
        else
        {
            for (auto i:s)
            {
                int y = king*(int)(i-'0');
                if(dist.count(y)==0)
                {
                    dist[y]=dist[king]+1;
                    q.push(y);
                }
            }
        }
    }
    return false;
}
int32_t main()
{

    FastIO();
    cin >> n >> x;
    if(bfs(x))
    {

    }
    else
    {
        cout<<"-1\n";
    }   
}