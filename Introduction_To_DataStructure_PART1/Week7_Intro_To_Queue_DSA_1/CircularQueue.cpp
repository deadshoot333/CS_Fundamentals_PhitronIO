#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=10;
template<class T>
class CircularQueue
{
    T a[MAX_SIZE];
    int l,r,sz;
    public:
    CircularQueue()
    {
        l=0;
        r=-1;
        sz=0;
    }
    void insert(T value)
    {
        if(sz>=MAX_SIZE)
        {
            cout<<"Size Full\n";
            return;
        }
        r++;
        if(r==MAX_SIZE)
        {
            r=0;
        }
        a[r]=value;
        sz++;
    }
    T dq()
    {
        if(sz==0)
        {
            cout<<"Queue Empty\n";
            return (T)INT_MIN;
        }
        if(l==MAX_SIZE)
        {
            l=0;
        }
        T popped=a[l];
        l++;
        sz--;
        return popped;
    }
    int size()
    {
        return r-l+1;
    }
    T front()
    {
        return a[l];
    }
};
int main()
{
    CircularQueue<char>q;
    q.insert('a');
    q.insert('r');
    q.insert('q');
    q.insert('m');
    cout<<"Front is = "<<q.front()<<"\nQueue is\n";
    while(q.size()!=0)
    {
        cout<<q.dq()<<"\n";
    }
}
