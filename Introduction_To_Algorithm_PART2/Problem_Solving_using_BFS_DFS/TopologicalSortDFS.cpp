#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 2e5;
vector<int> adj_list[N];
int visited[N];
stack<int> topo;
bool TopoSortPossible(int src)
{
    visited[src] = 1;
    // cout<<src<<" ";
    for (auto nodes : adj_list[src])
    {
        if (visited[nodes] == 0)
        {
            if (TopoSortPossible(nodes) == false)
            {
                return false;
            }
        }
        else if (visited[nodes] == 1)
        {
            return false;
        }
    }
    visited[src] = 2;
    topo.push(src);
    return true;
}
int main()
{

    FastIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (TopoSortPossible(i))
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        while (!topo.empty())
        {
            cout << topo.top() << " ";
            topo.pop();
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}