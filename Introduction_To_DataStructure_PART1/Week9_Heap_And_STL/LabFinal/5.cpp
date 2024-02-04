#include<bits/stdc++.h>
using namespace std;
const int max_size=100;
class Queue
{
    public:
    int a[max_size];
    int l,r;
    Queue()
    {
        l=0;
        r=-1;
    }
    void enqueue(int x)
    {
        if(r==max_size)
        {
            cout<<"Queue Full\n";
            return;
        }
        a[++r]=x;
    }
    int dequeue()
    {
        if (l>r)
        {
            cout<<"Queue Empty\n";
            return INT_MIN;
        }
        
        int cpy_front=a[l];
        l++;
        return cpy_front;
    }
    int front()
    {
        return a[l];
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    q.enqueue(5);
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    
}