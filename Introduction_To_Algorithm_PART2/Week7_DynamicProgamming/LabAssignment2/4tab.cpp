#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class Solution
{
public:
    int dp[38];
    int tribonacci(int n)
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};
int32_t main()
{

    FastIO();
    int n;
    cin >> n;
    Solution s;
    cout << s.tribonacci(n) << "\n";
}