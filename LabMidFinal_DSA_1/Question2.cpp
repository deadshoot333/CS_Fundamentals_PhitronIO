#include<bits/stdc++.h>
using namespace std;
vector<int>Sort(vector<int>&a)
{
    if(a.size()<=1)
    {
        return a;
    }
    int n=a.size();
    vector<int>b;
    vector<int>c;
    for(int i=0;i<n/2;i++)
    {
        b.push_back(a[i]);
    }
    for(int j=n/2;j<n;j++)
    {
        c.push_back(a[j]);
    }
    vector<int>sorted_b=Sort(b);
    vector<int>sorted_c=Sort(c);
    vector<int>sorted_a;
    int index1=0,index2=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(index1==sorted_b.size())
        {
            sorted_a.push_back(sorted_c[index2]);
            index2++;
        }
        else if(index2==sorted_c.size())
        {
            sorted_a.push_back(sorted_b[index1]);
            index1++;
        }
        else if(sorted_b[index1]==sorted_c[index2])
        {
            sorted_a.push_back(sorted_b[index1]);
            index1++;
            index2++;
        }
        else if(sorted_b[index1]<sorted_c[index2])
        {
            sorted_a.push_back(sorted_b[index1]);
            index1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[index2]);
            index2++;
        }
    }
    sorted_a.shrink_to_fit();
    return sorted_a;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int>ans=Sort(v);
    for(int i=0;i<n-1;i++)
    {
        cout<<ans[i]<<" ";
    }

}