// https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int visited[N][N];
int level[N][N];
int maze[N][N];
int dx[]={0,0,-1,1}; 
int dy[]={1,-1,0,0};
int n, m;
char path[N][N];
char pathP[]={'R','L','U','D'};
bool isSafe(int x,int y)
{
    if (x<0||x>=n||y<0||y>=m)
    {
        return false;
    }
    return true;
}
void BFS(pair<int,int>src)
{
    queue<pair<int,int>>q;
    q.push(src);
    while (!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if (isSafe(new_x,new_y) && visited[new_x][new_y]==0 && maze[new_x][new_y]!=-1)
            {
                q.push({new_x,new_y});
                level[new_x][new_y]=level[x][y]+1;
                visited[new_x][new_y]=1;
                path[x][y]=pathP[i];
            }
            
        }

    }
    
}

int main()
{
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
            else if (input[j] == 'A')
            {
                src = {i, j};
                maze[i][j]=2;
            }
            else if (input[j] == 'B')
            {
                dst = {i, j};
                maze[i][j]=3;
            }
        }
    }
    BFS(src);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << '\n';
    // }
    // cout<<src.first<<" "<<src.second<<"\n";
    // cout<<dst.first<<" "<<dst.second<<"\n";
    if (level[dst.first][dst.second])
    {
        cout<<"YES\n";
        cout<<level[dst.first][dst.second]<<"\n";
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i==src.first && j==src.second)||(i==dst.first && j==dst.second))
                {
                    //continue;
                }
                cout<<path[i][j];
            }
            cout<<"\n";   
        }
    }
    else
    {
        cout<<"NO\n";
    }
    
}