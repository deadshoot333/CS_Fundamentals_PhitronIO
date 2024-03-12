// https://docs.google.com/document/d/1MurqZb4vpfmWyA2Cx4k8-S9OdYHpcyIZN_QtwL0sZB0/edit
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
    const int N = 35;
    int dp[35];
    void init()
    {
        for (int i = 0; i < this->N; i++)
        {
            dp[i] = -1;
        }
    }
    int fib(int n)
    {
        this->init();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = fib(n - 1) + fib(n - 2);
    }
};
int32_t main()
{

    FastIO();
    Solution solve;
    int n;
    cin>>n;
    cout<<solve.fib(n)<<"\n";
}