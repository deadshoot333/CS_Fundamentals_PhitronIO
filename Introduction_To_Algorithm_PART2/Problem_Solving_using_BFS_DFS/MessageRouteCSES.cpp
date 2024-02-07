//https://cses.fi/problemset/task/1667
#include<bits/stdc++.h>
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int n,m;
const int N=2e5;
int visited[N];
int dist[N];
int parent[N];
vector<int>adj_list[N];
vector<int>result;
void if_possible(int src)
{
    //cout<<src<<" ";
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int king=q.front();
        q.pop();
        for(int nodes:adj_list[king])
        {
            if(visited[nodes]==0)
            {
                visited[nodes]=1;
                q.push(nodes);
                parent[nodes]=king;
                dist[nodes]=dist[king]+1;
                //result.push_back(nodes);
            }
        }        
    }
    if(visited[n]==0)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    else
    {
        int p=n;
        for(int i=0;i<=dist[n];i++)
        {
            result.push_back(p);
            p=parent[p];
        }
        cout<<result.size()<<"\n";
        for(auto it=result.rbegin();it!=result.rend();it++)
        {
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
    //return true;
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
    bool flag=false;
    /*if(*/if_possible(1);//)
    {
        // for(int i=2;i<=n;i++)
        // {
        //     cout<<parent[i]<<" ";
        // }
    }
    //else
    {
        //cout<<"IMPOSSIBLE\n";
    }   
}