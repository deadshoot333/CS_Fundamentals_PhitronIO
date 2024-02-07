#include<bits/stdc++.h>
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int n,m;
int visited[100];
vector<int>adj_list[100];

void DFS(int src)
{
    visited[src]=1;
    for(int i:adj_list[src])
    {
        if(visited[i]==0)
        {
            DFS(i);
        }
    }
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
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            DFS(i);
            count++;
        }
    }
    cout<<count<<"\n";
}