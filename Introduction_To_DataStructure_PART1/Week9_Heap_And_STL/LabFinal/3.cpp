#include<bits/stdc++.h>

using namespace std;



class node
{
public:
    int data;
    node * nxt;
    node * prv;
};

class LinkedList
{
public:
    node *head;
    node *tail;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz = 0;
    }

    node * CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            tail=head;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }
    void InsertAtTail(int data)
    {
        node *newnode=CreateNewNode(data);
        if(head==NULL)
        {
            head=newnode;
            tail=head;
            sz++;
        }
        else
        {
            tail->nxt=newnode;
            newnode->prv=tail;
            tail=newnode;
            sz++;
        }
    }
    void InsertAtMid(int data)
    {
        node *a = head;
        int cur_index = 0;
        while(cur_index!= (sz/2)-1)
        {
            a = a->nxt;
            cur_index++;
        }
            //a = a->nxt;
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node *b = a->nxt;
        b->prv = newnode;
        a->nxt = newnode;
        sz++;
    }
    void print()
    {
        node *curr=head;
        while (curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->nxt;
        }
        cout<<"\n";
        
    }
    void Merge(LinkedList a)
    {
        node *temp_b=this->tail;
        node *temp_a=a.head;
        temp_b->nxt=temp_a;
        temp_a->prv=temp_b;
        this->tail=a.tail;
    }
    ~LinkedList()
    {

    }
};
int main()
{
	LinkedList a;
	LinkedList b;

	a.InsertAtHead(1);
	a.InsertAtTail(5);
	a.InsertAtMid(3);
	a.InsertAtHead(0);
	a.InsertAtTail(10);
	a.print();	// prints 0 1 3 5 10
	b.InsertAtHead(10);
	b.InsertAtTail(50);
	b.InsertAtMid(30);
	b.InsertAtHead(9);
	b.InsertAtTail(100);
    b.print(); // prints  9 10 30 50 100
	
	a.Merge(b);
	a.print(); // prints  0 1 3 5 10 9 10 30 50 100
	b.print(); // prints  9 10 30 50 100
}