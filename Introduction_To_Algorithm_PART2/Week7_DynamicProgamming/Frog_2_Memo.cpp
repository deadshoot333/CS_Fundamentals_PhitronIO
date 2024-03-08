//https://vjudge.net/problem/AtCoder-dp_b
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
int n, k;
void init()
{
    for (int i = 0; i <= N; i++)
    {
        dp[i] = -1;
    }
}
int solve(int i)
{
    if (i <= 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int ans=INT_MAX;
    for (int j = 1;j<=k;j++)
    {
        ans=min(ans,solve(i-j)+abs(cost[i]-cost[i-j]));
    }
    dp[i]=ans;
    return ans;
}
int32_t main()
{

    FastIO();
    init();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    cout << solve(n) << " ";
}