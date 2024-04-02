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
int32_t main()
{

    FastIO();
    int m = 1e9 + 7;
    dp[0][0] = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string grid;
        cin >> grid;
        for (int j = 0; j < n; j++)
        {
            if (grid[j] == '.')
            {
                if (i > 0)
                {
                    (dp[i][j] += dp[i - 1][j])%=m;
                }
                if (j > 0)
                {
                    (dp[i][j] += dp[i][j - 1])%=m;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n - 1][n - 1];
}