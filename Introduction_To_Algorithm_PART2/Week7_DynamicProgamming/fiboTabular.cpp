#include <bits/stdc++.h>
using namespace std;

const int N = 2e4;
int dp[N];

int main()
{
    cout << "Enter the nth number = ";
    int n;
    cin >> n;
    // base case
    dp[1] = 1;
    dp[2] = 1;
    // calculating the answer from smaller sub-problems
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << "\n";
}