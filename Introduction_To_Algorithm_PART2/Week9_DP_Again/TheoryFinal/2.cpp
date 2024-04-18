#include<bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
 
int32_t main()
{ 
     
    FastIO();
    
 
}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>visited(n+1,0);
        vector<int> dist(n + 1, INT_MAX);
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({k, 0});
        while (!pq.empty()) {
            auto king = pq.top();
            pq.pop();
            int u = king.first;
            visited[u] = 1;
            for (auto child : adj[u]) {
                int v = child.first;
                int w = child.second;
                    if (dist[v] > w + dist[u]) {

                        dist[v] = w + dist[u];
                        pq.push({v,dist[v]});
                    }
                
            }
        }
        int mx = *max_element(dist.begin() + 1, dist.end());
        return mx == INT_MAX ? -1 : mx;
    }
};

