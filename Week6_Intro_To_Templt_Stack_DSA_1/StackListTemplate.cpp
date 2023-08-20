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
class StackList//insert first delte first(insert at head delte at head)
{
    node<T>*head;
    node<T>*tail;
    public:
    StackList()
    {
        head=NULL;
        tail=NULL;
    }
    void push(T x)
    {
        node<T>*newitem;
        newitem=new node<T>;
        newitem->data=x;
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
    T pop()
    {
        if(head==NULL)
        {
            assert(false);//assert(false) crashes the programme
        }
        node<T>*temp=head;
        head=head->next;
        T popped=temp->data;
        delete temp;
        return popped;
    }
    ~StackList()
    {
        
    }
};
int main()
{
    StackList<char>s;
    //s.push('c');
    //s.push('b');
    //s.push('a');
    cout<<s.pop()<<" "<<s.pop()<<" "<<s.pop()<<"\n";
}