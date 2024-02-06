// https://cses.fi/problemset/task/1678
#include <bits/stdc++.h>
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int n, m;
const int N = 2e5;
int visited[N];
vector<int>adj_list[N];
vector<int>track;
bool DFS(int src)
{   
    //cout<<src<<" ";
    visited[src]=1;
    for (int nodes:adj_list[src])
    {
        track.push_back(nodes);
        if (visited[nodes]==0)
        {
            if(DFS(nodes))
            {
                return true;
            }
        }
        else if (visited[nodes]==1)
        {
            //cout<<"Cycle Detected\n";
            //reverse(track.begin(),track.end());
            return true;
        }
        track.pop_back();
        
    }
    visited[src]=2;
    return false;
} 
int main()
{
    FastIO();
    cin>>n>>m;
    for (int i = 0; i <m; i++)
    {
       int u,v;
       cin>>u>>v;
       adj_list[u].push_back(v);
    }
    //int count=0;
    bool flag=false;
    for (int i = 1; i <=n; i++)
    {
        track.push_back(i);
        if (visited[i]==0 and DFS(i))
        {
                vector<int>ans={*track.rbegin()};
                for (auto it=track.rbegin()+1;it!=track.rend(); it++)
                {
                    ans.push_back(*it);
                    if(*it==*track.rbegin())
                    {
                        break;
                    }
                }
                cout<<ans.size()<<"\n";
                reverse(ans.begin(),ans.end());
                for (auto it:ans)
                {
                    cout<<it<<" ";
                }
                flag=true;
                break;
            //count++;
        }
        track.pop_back();
    }
    if(flag)
    {
        //cout<<"Cycle Detected\n";
        // cout<<track.size()<<"\n";
        // for (auto i:track)
        // {
        //     cout<<i<<" ";
        // }
        // //cout<<track[0]<<" ";
        // cout<<"\n";
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }
    //cout<<count<<"\n";
}