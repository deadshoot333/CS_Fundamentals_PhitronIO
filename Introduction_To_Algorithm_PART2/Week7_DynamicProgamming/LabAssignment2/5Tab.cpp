#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e5 + 5;
int dp[N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = INT_MAX;
    }
}
int32_t main()
{

    FastIO();
    init();
    int n;
    cin>>n;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=min(dp[i],1+dp[i-1]);
        if(i%2==0)
        {
            dp[i]=min(dp[i],1+dp[i/2]);
        }
        else if(i%3==0)
        {
            dp[i]=min(dp[i],1+dp[i/3]);
        }
    }
    cout<<dp[n]<<"\n";
}