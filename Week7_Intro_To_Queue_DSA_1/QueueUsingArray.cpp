#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=10;
class Queue
{
    int a[MAX_SIZE];
    int l,r;
    public:
    Queue()
    {
        l=0;
        r=-1;
    }
    bool empty()
    {
        if(l>r)
        {
            return true;
        }
        return false;
    }
    void enq(int value)
    {
        if(r==MAX_SIZE)
        {
            cout<<"Queue is Full\n";
            return; 
        }
        a[++r]=value;
    }
    int dq()
    {
        if(l>r)
        {
            cout<<"Queue is empty\n";
            return INT_MIN;
        }
        int popped=a[l];
        l++;
        return popped;
    }
    int size()
    {
        return r-l+1;
    }
    void display()
    {
        for(int i=l;i<=r;i++)
        {
            cout<<a[i]<<" ";
        }
    }
}q;
int main()
{
    q.enq(5);
    q.enq(6);
    q.enq(8);
    q.enq(7);
    q.display();
    cout<<"\n";
    while(!q.empty())
    {
        cout<<q.dq()<<"\n";
    }

}