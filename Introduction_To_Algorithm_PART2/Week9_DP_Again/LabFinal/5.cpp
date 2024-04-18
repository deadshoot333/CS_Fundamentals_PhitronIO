#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e3;
const int MAX_SUM = 1e5;
int dp[N + 1][MAX_SUM + 1];
int32_t main()
{

    FastIO();
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int target = 0; target <= MAX_SUM; target++)
        {
            dp[i][target]=dp[i-1][target];
            int with_taking = target - a[i-1];
            if (with_taking >= 0 and dp[i - 1][with_taking])
            {
                dp[i][target] = 1;
            }
        }
    }
    vector<int> result;
    for (int i = 1; i <= MAX_SUM; i++)
    {
        if (dp[n][i])
        {
            result.push_back(i);
        }
    }
    cout << result.size() << "\n";
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
