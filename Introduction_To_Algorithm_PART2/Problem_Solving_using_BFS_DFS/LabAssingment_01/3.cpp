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
bool hasCycle(int src)
{
    visited[src]=1;
    for(int i:adj_list[src])
    {
        if(visited[i]==0)
        {
            if(hasCycle(i))
            {
                return true;
            }
        }
        else if(visited[i]==1)
        {
            return true;
        }
    }
    visited[src]=2;
    return false;
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
    }
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            if(hasCycle(i))
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
 
