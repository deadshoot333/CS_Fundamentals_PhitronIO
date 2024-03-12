#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
int dp[N];
int cnt[N];
int a[N];
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void init()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
}
int32_t main()
{

    FastIO();
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    dp[0]=0;
    dp[1]=cnt[1];
    for(int i=2;i<N;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
    }
    cout<<dp[N-1]<<"\n";
}