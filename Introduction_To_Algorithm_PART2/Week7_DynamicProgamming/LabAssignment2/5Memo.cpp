#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e5 + 5;
int dp[N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
}
int solve(int n)
{

    if (n == 1)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int result = INT_MAX;
    result = min(result, 1 + solve(n - 1));
    if (n % 2 == 0)
    {
        result = min(result, 1 + solve(n / 2));
    }
    if (n % 3 == 0)
    {
        result = min(result, 1 + solve(n / 3));
    }
    dp[n] = result;
    return result;
}
int32_t main()
{

    FastIO();
    init();
    int n;
    cin >> n;
    cout << solve(n) << "\n";
}