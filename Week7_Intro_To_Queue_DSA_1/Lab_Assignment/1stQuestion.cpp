#include<bits/stdc++.h>
using namespace std;
template<class T>
class Queue
{
    public:
    T *a;
    int l;
    int r;
    int cap;
    int size;
    Queue()
    {
        a=new T[1];
        l=0;
        r=-1;
        cap=1;
        size=0;
    }
    void remove_circular()
    {
        if(l>r)
        {
            T *temp=new T[cap];
            int x=0;
            for(int i=l;i<cap;i++)
            {
                temp[x++]=a[i];
            }
            for(int i=0;i<=r;i++)
            {
                temp[x++]=a[i];
            }
            swap(a,temp);
            l=0;
            r=cap-1;
            delete [] temp;   
        }
    }
    void increase()
    {
        remove_circular();
        cap=cap*2;
        T *temp=new T[cap];
        for(int i=l;i<=r;i++)
        {
            temp[i]=a[i];
        }
        swap(a,temp);
        delete [] temp;
    }
    void enqueue(T data)
    {
        if(cap==size)
        {
            increase();
        }
        r++;
        if(r==cap)
        {
            r=0;
        }
        a[r]=data;
        size++;
    }
    void dequeue()
    {
        if(size==0)
        {
            return;
        }
        l++;
        if(l==cap)
        {
            l=0;
        }
        size--;
    }
    T front()
    {
        if(size==0)
        {
            return INT_MIN;
        }
        return a[l];
    }
};
int main()
{
    Queue<float>q;
    q.enqueue(5.6);
    q.enqueue(4.1);
    q.enqueue(3.4);
    q.enqueue(15.45);
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";

}