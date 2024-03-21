#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
}
int root, target;
vector<int> parent_list[N];
// in bfs we have kept child in the list but here we have to keep parent
int solve(int node)
{
    if (node == root)
    {
        return 0;
    }
    if (dp[node] != -1)
    {
        return dp[node];
    }
    int ans = 0;
    for (int parent : parent_list[node])
    {
        int parent_dist = solve(parent);
        ans = max(ans, parent_dist);
    }
    dp[node] = ans++;
    return ans;
}
int main()
{
    init();
    int n, edege;
    cin >> n >> edege;
    for (int i = 0; i < edege; i++)
    {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    cout << "Enter root:";
    cin >> root;
    cout << "Enter target: ";
    cin >> target;
    cout<<"Max Distance from "<<root<<" to "<<target<<" is :"<<solve(target) << "\n";
}