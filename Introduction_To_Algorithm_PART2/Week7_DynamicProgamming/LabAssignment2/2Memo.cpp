#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
int dp[N];
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void init()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
}
int solve(int n, int cost[])
{
    if (n == 0)
    {
        return 0;
    }
    if (n==1)
    {
        return cost[1];
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=max(solve(n-1,cost),solve(n-2,cost)+cost[n]);
    return dp[n];

}
int32_t main()
{

    FastIO();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        int n;
        cin >> n;
        int cost[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
        }
        cout << "Case " << i << ": " << solve(n, cost) << "\n";
    }
}