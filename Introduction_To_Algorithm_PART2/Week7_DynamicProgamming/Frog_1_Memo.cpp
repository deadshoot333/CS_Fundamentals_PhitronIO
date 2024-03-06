//https://vjudge.net/contest/325574#problem/A
#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e6;
int dp[N];
int cost[N];
int n;
void init()
{
    for (int i = 0; i <= N; i++)
    {
        dp[i] = -1;
    }
}
int solve(int i)
{
    if(i==2)
    {
        dp[i]=solve(i-1)+abs(cost[i]-cost[i-1]);
        return dp[i];// case when 100 10 
    }
    if(i==1)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    dp[i]=min(solve(i-1)+abs(cost[i]-cost[i-1]),solve(i-2)+abs(cost[i]-cost[i-2]));
    return dp[i];
}
int32_t main()
{

    FastIO();
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    cout<<solve(n)<<" ";
}