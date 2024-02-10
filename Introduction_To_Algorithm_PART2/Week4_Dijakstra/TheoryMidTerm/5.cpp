#include<bits/stdc++.h>
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
const int N=1e5;
int n,m;
vector<int>adj_list[N];
int visited[N];
bool bfs(int start)
{
    visited[start]=1;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int king=q.front();
        q.pop();
        for(auto child:adj_list[king])
        {
            if(visited[child]==0)
            {
                visited[child]=1;
                q.push(child);
            }
        }
    }
    if(visited[n]==0)
    {
        return false;
    }
    return true;
}
int main()
{ 
     
    FastIO();
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    if(bfs(1))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}