#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e3;
const int M = 1e3;
int a[N];
int dp[N][M];

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

int solve(int n, int target)
{
    if (n == 0)
    {
        if (target == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    int without_taking = solve(n - 1, target);
    if (a[n] > target)
    {
        dp[n][target] = without_taking;
        return without_taking;
    }
    int with_taking = solve(n - 1, target - a[n]);
    int result = without_taking or with_taking;
    dp[n][target] = result;
    return result;
}

int32_t main()
{

    FastIO();
    init();
    int n,target;
    cin>>n>>target;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<solve(n,target)<<"\n";
}