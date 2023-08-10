#include<bits/stdc++.h>
using namespace std;
vector<int>MergeSort(vector<int>&a)
{
    int n=a.size();
    if(n<=1)
    {
        return a;
    }
    vector<int>b;
    for(int i=0;i<n/2;i++)
    {
        b.push_back(a[i]);
    }
    vector<int>c;
    for(int i=n/2;i<n;i++)
    {
        c.push_back(a[i]);
    }
    vector<int>sorted_b=MergeSort(b);
    vector<int>sorted_c=MergeSort(c);
    vector<int>sorted_a;
    int index1=0,index2=0;
    for(int i=0;i<a.size();i++)
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
    vector<int>x=MergeSort(v);
    for(auto i:x)
    {
        cout<<i<<" ";
    }
}