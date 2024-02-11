#include<bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
const int N=1e5;
int dist[N];
int parent[N];
vector<pair<int,int>>adj_list[N]; 
int32_t main()
{ 
     
    FastIO();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        dist[i]=INT_MAX;
    }
    bool hasNegCycle=false;
    int last_updated_node;
    dist[1]=0; // 1 is used as source for this
    for(int i=1;i<=n;i++) //Bellman runs for 1 to n-1 but to check Negetive Cycle exists or not we have to run loop for another time.
    {
        for(int node=1;node<=n;node++)
        {
            for(auto adj_node:adj_list[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;
                if(dist[u]+w<dist[v])
                {
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                    if(i==n)
                    {
                        hasNegCycle=true;
                        last_updated_node=v;
                    }
                }
            }
        }
    }
    if(hasNegCycle)
    {
        cout<<"YES\n";
        int selected_node=last_updated_node;
        for(int i=1;i<=n-1;i++) 
        {
            selected_node=parent[selected_node];
        }
        int first_node=selected_node;
        vector<int>cycle;
        cycle.push_back(first_node);
        while(1)
        {
            selected_node=parent[selected_node];
            cycle.push_back(selected_node);
            if(selected_node==first_node)
            {
                break;
            }
        }
        for(auto it=cycle.rbegin();it!=cycle.rend();it++)
        {
            cout<<*it<<" ";
        }
    }
    else
    {
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<dist[i]<<" "; //distance are printed when graph is accurate i.e there is no negative cycle
        // }
        cout<<"NO\n";
    }
 
}