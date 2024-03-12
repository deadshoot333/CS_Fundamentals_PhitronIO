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
    int dp[31];
    int fib(int n)
    {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int32_t main()
{

    FastIO();
    Solution s;
    int n;
    cin>>n;
    cout<<s.fib(n)<<"\n";
}