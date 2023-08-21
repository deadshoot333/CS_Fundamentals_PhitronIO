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
        head=NULL;
        tail=NULL;
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
    void pop()
    {
        if(size==0)
        {
            assert(false);
        }
        else
        {
            node<T> *temp=head;
            head=head->next;
            size--;
            delete temp;
        }
    }
    T Top()
    {
        return head->data;
    }
    int get_size()
    {
        return size;
    }
    void print()
    {
        node<T>*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    ~Stack()
    {

    }
};
int main()
{
    Stack<int>st;
    Stack<int>temp;
    Stack<int>a;
    st.push(5);
    st.push(10);
    st.push(8);
    st.push(15);
    st.push(13);
    while(st.get_size()>0)
    {
        int top=st.Top();
        st.pop();
        while(temp.get_size()>0)
        {
            if(temp.Top()<top)
            {
                break;
            }
            st.push(temp.Top());
            temp.pop();
        }
        temp.push(top);
    }
    swap(st,temp);
    while(st.get_size()>0)
    {
        cout<<st.Top()<<" ";
        st.pop();
    }
}