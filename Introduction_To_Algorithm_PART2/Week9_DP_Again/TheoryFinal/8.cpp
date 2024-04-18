#include<bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
const int N=3e3+1;
int dp[N][N];
void init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-1;
        }
    }
} 
int LCS_length(string x,string y,int i,int j)
{
    if(i==0|| j==0)
    {
        dp[i][j]=0;
        return dp[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(x[i-1]==y[j-1])
    {
        return dp[i][j]=1+LCS_length(x,y,i-1,j-1);
    }
    else
    {
        int ans=0;
        if(i-1>0)
        {
            ans=max(ans,LCS_length(x,y,i-1,j));
        }
        if(j-1>0)
        {
            ans=max(ans,LCS_length(x,y,i,j-1));
        }
        return dp[i][j]=ans;
    }
}
string print_lcs(string x,string y)
{
    string result;
    int n=x.size();
    int m=y.size();
    while(n>0 and m>0)
    {
        if(x[n-1]==y[m-1])
        {
            result.push_back(x[n-1]);
            n--;
            m--;
        }
        else
        {
            if(dp[n-1][m]>dp[n][m-1])
            {
                n--;
            }
            else
            {
                m--;
            }
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
int32_t main()
{ 
     
    FastIO();
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    init();
    int lcs=LCS_length(x,y,n,m);
    cout<<print_lcs(x,y)<<"\n";
}