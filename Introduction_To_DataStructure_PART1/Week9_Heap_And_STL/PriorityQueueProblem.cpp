#include<bits/stdc++.h>
using namespace std;
int Digit(int x)
{
    int result=0;
    while(x!=0)
    {
        x/=10;
        result++;
    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    vector<int>a,b;
    priority_queue<int>p1,p2;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        p1.push(a[i]);
        p2.push(b[i]);
    }
    int ans=0;
    while(p1.size()!=0)
    {
        int x=p1.top();
        int y=p2.top();
        if(x==y)
        {
            p1.pop();
            p2.pop();
            continue;
        }
        ans++;
        if(x>y)
        {
            p1.pop();
            p1.push(Digit(x));
            cout<<" From 1st: "<<p1.top()<<" ";
        }
        else
        {
            p2.pop();
            p2.push(Digit(y));
            cout<<" From 2nd: "<<p2.top()<<" ";
        }
    }
    cout<<ans<<"\n";
}