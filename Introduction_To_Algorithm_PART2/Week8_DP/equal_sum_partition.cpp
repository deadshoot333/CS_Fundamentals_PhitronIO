// https://leetcode.com/problems/partition-equal-subset-sum/description/
#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 201;
const int M = 20001;
int dp[N][M];
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0)
        {
            return false;
        }
        totalSum /= 2;
        dp[0][0] = 1;
        for (int i = 1; i <= totalSum; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 1; j <= totalSum; j++)
            {
                int without_taking = dp[i - 1][j];
                if (j < nums[i - 1])
                {
                    dp[i][j] = without_taking;
                }
                else
                {
                    int with_taking = dp[i - 1][j - nums[i - 1]];
                    dp[i][j] = with_taking or without_taking;
                }
            }
        }
        return dp[nums.size()][totalSum];
    }
};
int32_t main()
{

    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout<<s.canPartition(nums)<<"\n";
}