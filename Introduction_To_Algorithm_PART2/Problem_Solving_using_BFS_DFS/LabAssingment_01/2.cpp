#include<bits/stdc++.h>
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int visited[6];
vector<int>adj_list[6];
int dist[6];
void BFS(int src)
{
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int king=q.front();
        q.pop();
        //cout<<king<<" ";
        visited[king]=1;
        for(int child:adj_list[king])
        {
            if(visited[child]==0)
            {
                visited[child]=1;
                dist[child]=dist[king]+1;
                q.push(child);
            }
        }
    }
    
}
void addEdge(int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
} 
int main()
{ 
     
    FastIO();
    addEdge(0,1);
    addEdge(0,3);
    addEdge(0,4);
    addEdge(1,2);
    addEdge(1,5);
    addEdge(2,4);
    addEdge(5,4);
    BFS(0);
    for(int i=0;i<6;i++)
    {
        cout<<"node "<<i<<"-> level: "<<dist[i]<<"\n";
    }
}