// Question Link:https://docs.google.com/document/d/1RBFq0CxGJVo6ZXNxfxwkuFQbTuj-bxUUQs7ZqbUpehs/edit
#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int n, m;
int maze[1001][1001];
int visited[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void init(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}
bool isSafe(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    return true;
}
int dfs(int x, int y)
{
    int ans;
    ans = maze[x][y];
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (isSafe(new_x, new_y) and visited[new_x][new_y] == 0 and maze[new_x][new_y] != 0)
        {
            ans += dfs(new_x, new_y);
        }
    }
    return ans;
}

int32_t main()
{

    FastIO();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        init(n,m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout<<maze[i][j];
        //     }
        //     cout<<"\n";
        // }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] != 0 and visited[i][j] == 0)
                {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        cout << ans << "\n";
    }
}