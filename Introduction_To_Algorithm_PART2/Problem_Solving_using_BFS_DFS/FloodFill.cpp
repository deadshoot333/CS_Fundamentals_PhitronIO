#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int visited[N][N];
int maze[N][N];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isSafe(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;
}

void BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (isSafe(new_x, new_y) && visited[new_x][new_y] == 0 && maze[new_x][new_y] != -1)
            {
                q.push({new_x, new_y});
                visited[new_x][new_y] = 1;
            }
        }
    }
}

pair<int, int> Give_unvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if (visited[i][j] == 0 && maze[i][j] == 0)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}
int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> m;
    pair<int, int> src, dst;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == '#')
            {
                maze[i][j] = -1;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << '\n';
    // }
    int result = 0;
    while (1)
    {
        if (Give_unvisited() == pair<int, int>(-1, -1))
        {
            break;
        }
        else
        {
            BFS(Give_unvisited());
            result++;
        }
    }
    cout << result << "\n";
}