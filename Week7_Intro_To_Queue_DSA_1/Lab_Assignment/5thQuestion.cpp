#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node
{
    public:
    T data;
    Node *next;
    Node *prev;
};
template<class t>
class Deque
{
    Node<t>*head;
    Node<t>*tail;
    int size;
    public:
    Deque()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    void push_front(t value)
    {
        Node<t>*newitem;
        newitem= new Node<t>;
        newitem->data=value;
        newitem->next=NULL;
        newitem->prev=NULL;
        if(head==NULL)
        {
            head=newitem;
            tail=head;
        }
        else
        {
            newitem->next=head;
            head->prev=newitem;
            head=newitem;
        }
        size++;
    }
    void push_back(t value)
    {
        Node<t> *newitem;
        newitem=new Node<t>;
        newitem->data=value;
        newitem->next=NULL;
        newitem->prev=NULL;
        if(head==NULL)
        {
            head=newitem;
            tail=head;
        }
        else
        {
            tail->next=newitem;
            newitem->prev=tail;
            tail=newitem;
        }
        size++;
    }
    void pop_back()
    {
        if(size==0)
        {
            cout<<"Empty\n";
            return;
        }
        else if(size==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            size--;
            return;
        }
        Node<t> *temp;
        temp=tail;
        tail=tail->prev;
        delete temp;
        tail->next=NULL;
        size--;
    }
    void pop_front()
    {
        if(size==0)
        {
            cout<<"EMPTY\n";
            return;
        }
        else if(size==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            size--;
            return;
        }
        Node<t>*temp;
        temp=head;
        head=head->next;
        delete temp;
        head->prev=NULL;
        size--;
    }
    t front()
    {
        t item=head->data;
        return item;
    }
    t back()
    {
        t item=tail->data;
        return item;
    }
    void print()
    {
        if(size==0)
        {
            cout<<"EMPTY\n";
            return;
        }
        Node<t>*temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void printReverse()
    {
        if(size==0)
        {
            cout<<"EMPTY\n";
            return;
        }
        Node<t>*temp=tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<"\n";
    }
    ~Deque()
    {

    } 
};
int main()
{
    Deque<char>d;
    d.push_back('A');
    d.push_front('G');
    d.push_back('B');
    d.push_back('C');
    d.push_back('D');
    d.push_back('E');
    d.push_back('F');
    d.pop_back();
    d.print();
    d.pop_front();
    d.printReverse();

}