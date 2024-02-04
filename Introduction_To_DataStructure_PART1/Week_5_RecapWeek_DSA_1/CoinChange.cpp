#include<bits/stdc++.h>
using namespace std;
vector<int>coins={1,3,4};
int minCoins(int n)
{
    if(n==0)
    {
        return 0;
    }
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        if(n>=coins[i])
        {
            ans=min(ans,1+minCoins(n-coins[i]));
            
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<minCoins(n)<<"\n";
}