#include<bits/stdc++.h>
using namespace std;
template<class T>
class StackDynamic
{
    T *a;
    int top=-1;
    int capacity;
    int size=0;
    int current_size;
    public:
    StackDynamic()
    {
        a=new T[1];
        top=-1;
        capacity=1;
        size=1;
        current_size=0;
    }
    void increase()
    {
        T *temp;
        capacity*=2;
        temp=new T[capacity];
        for(int i=0;i<current_size;i++)
        {
            temp[i]=a[i];
        }
        swap(a,temp);
        delete [] temp;
    }
    void push(T x)
    {
        if(current_size==capacity)
        {
            increase();
        }
        top++;
        a[top]=x;
        current_size++;
    }
    T pop()
    {
        T popped=a[top];
        top--;
        current_size--;
        return popped;
    }
    ~StackDynamic()
    {
        delete [] a;
    }
};
int main()
{
    StackDynamic<double>s;
    s.push(10.5);
    s.push(5.6);
    s.push(25.1);
    cout<<s.pop()<<" "<<s.pop()<<" "<<s.pop()<<"\n";
}