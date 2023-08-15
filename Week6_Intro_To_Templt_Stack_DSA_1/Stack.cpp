#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=10;

class StackStatic
{
    int array[MAX_SIZE];
    protected:
    int top;
    int current_Size;
    public:
    StackStatic()
    {
        top=-1;
        current_Size=0;
    }
    virtual void push(int x)
    {
        if(current_Size==MAX_SIZE)
        {
            cout<<"Stack Overflow\n";
            return;
        }
        top++;
        array[top]=x;
        current_Size++;
    }
    virtual int pop()
    {
        if(current_Size==0)
        {
            return INT_MIN;
        }
        current_Size--;
        int popped=array[top];
        top--;
        return popped;
    }
    virtual ~StackStatic()
    {

    }  
};
class StackDynamic:public StackStatic
{
    int *dynamicStack;
    int capacity;
    public:
    StackDynamic()
    {
        dynamicStack=new int[1];
        capacity=1;
        current_Size=0;
    }
    void increase_size()
    {
            capacity*=2;
            int *temp;
            temp=new int[capacity];
            for(int i=0;i<capacity;i++)
            {
                temp[i]=dynamicStack[i];
            }
            swap(dynamicStack,temp);
            delete [] temp;
    }
    void push(int x)
    {
        if(current_Size==capacity)
        {
            increase_size();
        }
        top++;
        dynamicStack[top]=x;
        current_Size++;
    }
    int pop()
    {
        if(current_Size==0)
        {
            return INT_MIN;
        }
        int popped=dynamicStack[top];
        top--;
        current_Size--;
        return popped;
    }
    ~StackDynamic()
    {
        delete [] dynamicStack;
    }
};
int main()
{
    StackStatic s;
    s.push(10);
    s.push(9);
    s.push(8);
    cout<<"Stack Elements= "<<s.pop()<<"->"<<s.pop()<<"->"<<s.pop()<<"\n";
    StackDynamic d;
    d.push(15);
    d.push(10);
    d.push(25);
    cout<<" Dynamic Stack Elements= "<<d.pop()<<"->"<<d.pop()<<"->"<<d.pop()<<"\n";
    
    return 0;
}