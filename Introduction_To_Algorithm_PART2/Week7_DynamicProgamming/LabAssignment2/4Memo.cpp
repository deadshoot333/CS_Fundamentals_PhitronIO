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
    int dp[39];
    void init()
    {
        for (int i = 0; i < 39; i++)
        {
            dp[i] = -1;
        }
    }
    int tribonacci(int n)
    {
        this->init();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] =
                   tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
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