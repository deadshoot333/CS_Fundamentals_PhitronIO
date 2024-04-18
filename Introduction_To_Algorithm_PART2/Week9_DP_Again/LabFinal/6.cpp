#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 2e4 + 5;
int visited[N];
vector<int> adj_list[N];
char node_type[N];
void init()
{
    memset(visited, false, sizeof(visited));
    memset(node_type, 'L', sizeof(node_type));
    for (int i = 0; i < N; i++)
    {
        adj_list[i].clear();
    }
}
int bfs(int start)
{
    visited[start] = 1; //'considering first as L'
    node_type[start] = 'L';
    int lykan = 0, vampire = 0;
    lykan++;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int king = q.front();
        q.pop();
        for (auto child : adj_list[king])
        {
            if (visited[child] == 0)
            {
                visited[child] = 1;
                q.push(child);
                if (node_type[king] == 'L')
                {
                    node_type[child] = 'V';
                    vampire++;
                }
                else
                {
                    node_type[child] = 'L';
                    lykan++;
                }
            }
        }
    }
    int mx = max(lykan, vampire);
    return mx;
}
int32_t main()
{

    FastIO();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(visited[i]==0 and !adj_list[i].empty())
            {
                sum+=bfs(i);
            }
        }
        cout<<"Case "<<t<<": "<<sum<<"\n";
    }
}