#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int n, m;
bool flag;
int maze[1000][1000];
int visited[1000][1000];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char path[] = {'R', 'L', 'U', 'D'};
pair<int, int> parent[1000][1000];
pair<int, int> dst;
bool isValid(int x, int y)
{
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
    {
        return false;
    }
    return true;
}

void bfs(pair<int, int> start)
{
    visited[start.first][start.second] = 1;
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        auto king = q.front();
        q.pop();
        int x = king.first;
        int y = king.second;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (isValid(new_x, new_y) and maze[new_x][new_y] != -1 and visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y});
                parent[new_x][new_y] = {x, y};
            }
            if (maze[new_x][new_y] == 2)
            {
                dst = {new_x, new_y};
                flag = true;
                return;
            }
        }
    }
}
int main()
{

    FastIO();
    cin >> n >> m;
    vector<string> input;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        input.push_back(x);
    }
    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if ((j == 0 || j == m - 1) and input[i][j] == '.')
            {
                maze[i][j] = 2;
            }
            if (input[i][j] == 'A')
            {
                start = {i, j};
                maze[i][j] = 2;
            }

            if (input[i][j] == '.')
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = -1;
            }
            if (input[0][j] == '.')
            {
                maze[0][j] = 2;
            }
            if (input[n - 1][j] == '.')
            {
                maze[n - 1][j] = 2;
            }
        }
    }
    bfs(start);
    pair<int, int> curr = dst;
    string result;
    if (flag)
    {
        cout << "YES\n";
        while (curr != start)
        {
            pair<int, int> prev;
            prev = parent[curr.first][curr.second];
            int x = curr.first - prev.first;
            int y = curr.second - prev.second;
            for (int i = 0; i < 4; i++)
            {
                if (dx[i] == x and dy[i] == y)
                {
                    result.push_back(path[i]);
                    break;
                }
            }

            curr = prev;
        }
        cout << result.size() << "\n";
        for (auto i = result.rbegin(); i != result.rend(); i++)
        {
            cout << *i;
        }
    }
    else
    {
        cout << "NO\n";
    }
}