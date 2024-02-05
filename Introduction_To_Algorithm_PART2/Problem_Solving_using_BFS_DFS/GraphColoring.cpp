// https://cses.fi/problemset/task/1668
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int n,m;
int visited[N];
int color[N];
vector<int>adj_list[N];
bool DFS(int src)
{
    //cout<<src<<" ";
    visited[src]=1;
    for (int i:adj_list[src])
    {
        if (visited[i]==0)
        {
            if (color[src]==1)
            {
                color[i]=2;
            }
            else
            {
                color[i]=1;
            }
            bool is_bicolorable=DFS(i);
            if (!is_bicolorable)
            {
                return false;
            }
            
        }
        if (color[src]==color[i])
        {
            return false;
        }
    }
    return true;
}
int32_t main()
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
    bool flag=true;
    for (int i = 1; i <=n; i++)
    {
        if (visited[i]==0)
        {
            color[i]=1;
            if(DFS(i))
            {
                count++;
            }
            else
            {
                flag=false;
            }
        }
        
    }
    if (flag)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<color[i]<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }
    cout<<"\n";
}