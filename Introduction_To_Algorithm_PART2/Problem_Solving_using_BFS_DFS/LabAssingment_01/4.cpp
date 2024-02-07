#include<bits/stdc++.h>
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int n,m;
int visited[100];
int color[100];
vector<int>adj_list[100];
bool isBipartite(int src)
{
    visited[src]=1;
    for(int i:adj_list[src])
    {
        if(visited[i]==0)
        {
            if(color[src]==1)
            {
                color[i]=2;
            }
            else
            {
                color[i]=1;
            }
            if(isBipartite(i)==false)
            {
                return false;
            }

        }
        else
        {
            if(color[src]==color[i])
            {
                return false;
            }
        } 

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
    bool flag=false;   
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            color[i]=1;
            if(isBipartite(i))
            {
                flag=true;
                break;
            }
        }
    }
    if(flag)
    {
        cout<<"YES\n";       
    }
    else
    {
        cout<<"NO\n";
    }
}