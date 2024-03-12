// https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N][4];
int happiness[N][4];
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = -1;
        }
    }
}
int solve(int n, int x)
{
    if (n == 1)
    {
        return happiness[n][x];
    }
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    for (int i = 1; i <= 3; i++)
    {
        if (i == x)
        {
            continue;
        }
        dp[n][x] = max(solve(n - 1, i) + happiness[n][x], dp[n][x]);
    }
    return dp[n][x];
}
int main()
{
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> happiness[i][j];
        }
    }
    cout << max({solve(n, 1), solve(n, 2), solve(n, 3)});
}