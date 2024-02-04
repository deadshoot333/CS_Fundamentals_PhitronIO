#include<bits/stdc++.h>
using namespace std;
vector<int>QuickSort(vector<int>&a)
{
    if(a.size()<=1)
    {
        return a;
    }
    int pivot=rand()%a.size();
    vector<int>b;
    vector<int>c;
    for(int i=0;i<a.size();i++)
    {
        if(i==pivot)
        {
            continue;
        }
        if(a[i]<=a[pivot])
        {
            b.push_back(a[i]);
        }
        else
        {
            c.push_back(a[i]);
        }
    }
    vector<int>sorted_c=QuickSort(c);
    vector<int>sorted_b=QuickSort(b);
    vector<int>sorted_a;
    for(int i=0;i<sorted_c.size();i++)
    {
        sorted_a.push_back(sorted_c[i]);
    }
    sorted_a.push_back(a[pivot]);
    for(int j=0;j<sorted_b.size();j++)
    {
        sorted_a.push_back(sorted_b[j]);
    }
    return sorted_a;
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
    vector<int>ans=QuickSort(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}