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
class List_
{
    Node<t>*head=NULL;
    Node<t>*tail=NULL;
    public:
    void enqueue(t value)
    {
        Node<t> *newitem;
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
            tail->next=newitem;
            tail=newitem;
        }
    }
    void dequeue()
    {
        Node<t>*temp=head;
        head=head->next;
        delete temp;
    }
    void display()
    {
        cout<<"\n";
        Node<t>*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    ~List_()
    {

    }
};
int main()
{
    List_<char>l;
    l.enqueue('a');   
    l.enqueue('r');   
    l.enqueue('q');   
    l.enqueue('a');   
    l.enqueue('m');
    l.display();
    l.dequeue();
    l.display();   
}