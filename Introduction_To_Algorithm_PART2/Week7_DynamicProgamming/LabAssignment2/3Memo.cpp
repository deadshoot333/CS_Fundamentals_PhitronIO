#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
int dp[N];
int cnt[N];
int a[N];
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
int solve(int i)
{
    if (i > N)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    return dp[i] = max(solve(i + 1), solve(i + 2) + cnt[i] * i);
}
int32_t main()
{

    FastIO();
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    cout << solve(0) << "\n";
}