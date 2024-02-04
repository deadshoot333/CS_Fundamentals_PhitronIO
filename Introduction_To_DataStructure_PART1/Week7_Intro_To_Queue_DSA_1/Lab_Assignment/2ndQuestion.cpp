#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node
{
    public:
    T data;
    Node *next;
};
template<class t>
class Stack
{
    public:
    Node<t>*head;
    Node<t>*tail;
    Stack()
    {
        head=NULL;
        tail=NULL;
    }
    void push(t value)
    {
        Node<t>*newitem;
        newitem=new Node<t>;
        newitem->data=value;
        newitem->next=NULL;
        if(head==NULL)
        {
            head=newitem;
            tail=head;
        }
        else
        {
            newitem->next=head;
            head=newitem;
        }
    }
    t pop()
    {
        t cpy;
        Node<t>*temp;
        temp=head;
        cpy=head->data;
        head=head->next;
        delete temp;
        return cpy;
    }
    void display()
    {
        Node<t>*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};
int main()
{
    Stack<float>st;
    st.push(5.4);
    st.push(3.56);
    st.push(4.12);
    st.display();
    cout<<st.pop()<<" ";
    cout<<st.pop()<<" ";
}