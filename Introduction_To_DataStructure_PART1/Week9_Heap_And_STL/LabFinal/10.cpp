#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int>s;
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        s.insert(b[i]);
    }
    for (auto it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    

}