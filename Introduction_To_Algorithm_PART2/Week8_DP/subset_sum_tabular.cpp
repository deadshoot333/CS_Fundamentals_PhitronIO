#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int N = 1e3;
const int M = 1e3;
int a[N];
int dp[N][M];

int32_t main()
{

    FastIO();
    int n, target;
    cin >> n >> target;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=target;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            int without_taking=dp[i-1][j];
            if(j<a[i])
            {
                dp[i][j]=without_taking;
            }
            else
            {
                int with_taking=dp[i-1][j-a[i]];
                dp[i][j]=with_taking or without_taking;
            }
        }
    }
    cout<<dp[n][target]<<"\n";
}