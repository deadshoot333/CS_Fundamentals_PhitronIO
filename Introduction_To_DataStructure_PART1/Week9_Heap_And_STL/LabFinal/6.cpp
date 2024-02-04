#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>dq;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        dq.push_back(x);
    }
    while(dq.size()!=0)
    {
        if (dq.front()<dq.back())
        {
            cout<<dq.front()<<" ";
            dq.pop_front();
            
        }
        else
        {
            cout<<dq.back()<<" ";
            dq.pop_back();
            
        }
        
    }
    cout<<"\n";
}