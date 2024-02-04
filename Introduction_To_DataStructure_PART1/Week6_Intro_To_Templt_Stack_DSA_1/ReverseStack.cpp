#include<bits/stdc++.h>
using namespace std;
template<class T>
class node
{
    public:
    T data;
    node *next;
};
template<class T>
class Stack
{
    node<T>*head;
    node<T>*tail;
    int size;
    public:
    Stack()
    {
        size=0;
    }
    void push(T value)
    {
        node<T>*newitem;
        newitem=new node<T>;
        newitem->data=value;
        newitem->next=NULL;
        if(head==NULL)
        {
            head=newitem;
            tail=head;
            size++;
        }
        else
        {
            newitem->next=head;
            head=newitem;
            size++;
        }
    }
    T top()
    {
        node<T>*temp=head;
        return temp->data;
    }
    void pop()
    {
            node<T>*temp=head;
            head=head->next;
            delete temp;
            size--;
    }
    int get_size()
    {
        return size;
    }
~Stack()
{

}

};
int main()
{
    Stack<int>s;
    s.push(10);
    s.push(15);
    s.push(25);
    Stack<int>temp;
    while(s.get_size()>0)
    {
        temp.push(s.top());
        s.pop();
    }
    swap(s,temp);
    while(s.get_size()>0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}