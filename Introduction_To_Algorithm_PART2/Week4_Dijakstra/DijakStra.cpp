//https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int n,m;    
const int N=1e6;
int visited[N];
int dist[N];
int parent[N];
vector<pair<int,int>>adj_list[N];
void INIT()
{
    for(int i=0;i<N;i++)
    {
        dist[i]=1e15;
    }
}
void Dijakstra(int start)
{
    dist[start]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        auto king=pq.top();
        int u=king.second;
        int w=king.first;
        pq.pop();
        visited[u]=1;
        for(auto child:adj_list[u])                               
        {
            int child_node=child.second;
            int child_cost=child.first;
            if(visited[child_node]==0)
            {
                if(dist[child_node]>dist[u]+child_cost)
                {
                    dist[child_node]=dist[u]+child_cost;
                    parent[child_node]=u;
                    pq.push({-1*dist[child_node],child_node});  
                }
            }
        }
    }
} 
int32_t main()
{ 
     
    FastIO();
    INIT();
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({w,v});
        adj_list[v].push_back({w,u});
    }
    int src=1;
    int currentNode=n;
    vector<int>result;
    Dijakstra(1);
    if(visited[n]==0)
    {
        cout<<"-1\n";
        return 0;
    }
    while(currentNode!=src)
    {
        result.push_back(currentNode);
        currentNode=parent[currentNode];
    }
    cout<<src<<" ";
    for(auto it=result.rbegin();it!=result.rend();it++)
    {
        cout<<*it<<" ";
    }
}