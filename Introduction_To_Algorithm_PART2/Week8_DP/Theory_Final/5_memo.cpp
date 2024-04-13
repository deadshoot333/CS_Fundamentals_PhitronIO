#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e4 + 5;
int dp[N][N];
int m = 1e9 + 7;
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }
}
int solve(vector<string> &s, int i, int j, int n)
{
    if (i == n - 1 and j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n || s[i][j] == '*')
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    return dp[i][j] = (solve(s, i + 1, j, n) % m + solve(s, i, j + 1, n) % m) % m;
}
int32_t main()
{

    FastIO();
    init();
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cout << solve(s, 0, 0, n) << "\n";
}