//This method reduces time 
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
void DFS(int x,int y)
{
    visited[x][y]=1;
    for (int i = 0; i < 4; i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if (isSafe(new_x,new_y) && maze[new_x][new_y]==0 && visited[new_x][new_y]==0)
        {
            DFS(new_x,new_y);
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j]==0 && visited[i][j]==0)
            {
                DFS(i,j);
                result++;
                /* code */
            }
            
        }
        
    }
   cout << result << "\n";
}