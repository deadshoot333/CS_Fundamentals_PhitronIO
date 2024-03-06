#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e6;
int dp[N];
int cost[N];
int n;
void init()
{
    for (int i = 0; i <= N; i++)
    {
        dp[i] = -1;
    }
}
int32_t main()
{

    FastIO();
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    dp[1] = 0;
    dp[2] = dp[1] + abs(cost[1] - cost[2]);
    for (int i = 3; i <= n; i++)
    {
        dp[i]=min(dp[i-1]+abs(cost[i-1]-cost[i]),dp[i-2]+abs(cost[i-2]-cost[i]));
    }
    cout<<dp[n]<<" ";
}