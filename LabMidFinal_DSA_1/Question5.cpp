#include<bits/stdc++.h>
using namespace std;
int getMax(vector<int>&v,int mx,int i)
{
    if(i>=v.size())
    {
        return mx;     
    }
    if(v[i]>mx)
    {
        mx=v[i];
    }
    int ans=getMax(v,mx,i+1);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<getMax(v,v[0],0)<<"\n";
}