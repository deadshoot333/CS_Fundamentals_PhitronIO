//Question Link: https://docs.google.com/document/d/1tc9vHcC96zFZ2r8eOrNRSDtNUbiUFqvQOgoq8n4YtI0/edit
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
bool hasCycle(int start,int parent)
{
    visited[start]=1;
    for(auto i:adj_list[start])
    {
        if(visited[i]==0)
        {
            if(hasCycle(i,start))
            {
                return true;
            }
        }
        else if(i!=parent) // emn ekta child e ashlam jar parent agei determine kora hoyeche
        {
            return true;
        }
    }
    visited[start]=2;
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
        adj_list[v].push_back(u);
    }
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 and hasCycle(i,-1))
        {
            cout<<"Cycle Exist\n";
            flag=true;
            break;
        }
    }
    if(flag==false)
    {
        cout<<"No Cycle\n";
    }
}