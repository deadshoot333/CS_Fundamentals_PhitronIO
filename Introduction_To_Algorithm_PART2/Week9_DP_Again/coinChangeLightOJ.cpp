// https://lightoj.com/problem/coin-change-i
#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int coins[60], limit[60];
int dp[1001][1001];
int m = 100000007;
void init()
{
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dp[i][j] = -1;
        }
    }
}
int fun(int n, int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    int ans = fun(n - 1, k);
    for (int i = 1; i <= limit[n]; i++)
    {
        if (k - i * coins[n] < 0)
        {
            break;
        }

        int res = fun(n - 1, k - i * coins[n]);
        ans = (ans + res) % m;
    }
    dp[n][k] = ans;
    return ans;
}
int32_t main()
{

    FastIO();
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        init();
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <=n; i++)
        {
            cin >> coins[i];
        }
        for (int i = 1; i <=n; i++)
        {
            cin >> limit[i];
        }
        cout << "Case " << T << ": " << fun(n, k) << "\n";
    }
}