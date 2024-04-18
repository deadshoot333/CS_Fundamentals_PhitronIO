#include<bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
const int N=1e6+1 ;
const int M=1e9+7;
int dp[N]; 
int32_t main()
{ 
     
    FastIO();
    int n,target;
    cin>>n>>target;
    int coins[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>coins[i];
    }
    dp[0]=1;
    for(int k=1;k<=target;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(k-coins[i]>=0)
            {
                dp[k]+=dp[k-coins[i]];
                dp[k]%=M;
            }
        }
    }
    cout<<dp[target]<<"\n";
}