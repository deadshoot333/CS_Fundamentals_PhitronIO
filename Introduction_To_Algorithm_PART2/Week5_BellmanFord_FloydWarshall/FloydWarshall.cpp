#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e3;
int dist[N][N];
int32_t main()
{

    FastIO();
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = 1e15;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        int x, y;
        cin >> x >> y;
        if (dist[x][y] == 1e15)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dist[x][y] << "\n";
        }
    }
}