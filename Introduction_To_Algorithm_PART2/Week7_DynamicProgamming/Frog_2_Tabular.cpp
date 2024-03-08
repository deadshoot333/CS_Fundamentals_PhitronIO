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
int32_t main()
{

    FastIO();
    init();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i]=INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if(i-j<=0)
            {
                break;
            }
            dp[i] = min(dp[i], dp[i - j] + abs(cost[i] - cost[i - j]));
        }
    }
    cout << dp[n] << " ";
}