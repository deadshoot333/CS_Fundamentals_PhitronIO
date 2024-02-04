#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<string>q;
    q.push("1");
    for(int i=1;i<=n;i++)
    {
        string front=q.front();
        string frontCpy=q.front();
        q.pop();
        cout<<"Binary representaion of "<<i<<" : "<<front<<"\n";
        front+="0";
        q.push(front);
        frontCpy+="1";
        q.push(frontCpy);
    }
}