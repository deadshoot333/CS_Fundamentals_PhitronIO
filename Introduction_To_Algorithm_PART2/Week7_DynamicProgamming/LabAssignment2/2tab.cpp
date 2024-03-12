#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int dp[N];
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
 
int32_t main()
{ 
     
    FastIO();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        int cost[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
        }
        dp[0]=0;
        dp[1]=cost[1];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-2]+cost[i],dp[i-1]);
        }
        cout << "Case " << i << ": " <<dp[n]<< "\n";
    }
 
}