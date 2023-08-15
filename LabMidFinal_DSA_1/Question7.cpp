#include<bits/stdc++.h>

using namespace std;



class node
{
public:
    int data;
    node * nxt;
    node * prv;
};

class DoublyLinkedList
{
public:
    node *head;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    //Creates a new node with the given data and returns it O(1)
    node * CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    //Inserts a node with given data at head O(1)
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }

    //Inserts the given data at the given index O(n)
    void Insert(int index, int data)
    {
        if(index > sz)
        {
            return;
        }
        if(index==0)
        {
            InsertAtHead(data);
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index!= index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // a = cur_index - 1
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node *b = a->nxt;
        b->prv = newnode;
        a->nxt = newnode;
        sz++;
    }
    void DeleteAtHead()
    {
        node *temp=head;
        head=head->nxt;
        delete temp;
    }
    //Deletes the given index O(n)
    void Delete(int index)
    {
        if(index >= sz)
        {
            cout<<index<<" doesn't exist.\n";
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->prv;
        node *c = a->nxt;
        if(b!=NULL)
        {
            b->nxt = c;
        }
        if(c!= NULL)
        {
            c->prv = b;
        }
        delete a;
        if(index==0)
        {
            head = c;
        }
        sz--;
    }

    //Prints the linked list O(n)
    void Traverse()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    // Returns the size of linked list O(1)
    int getSize()
    {
        return sz;
    }

    //Reverse the doubly linked list O(n)
    void Reverse()
    {
        if(head==NULL)
        {
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != sz-1)
        {
            a = a->nxt;
            cur_index++;
        }
        // last index is in a

        node *b = head;
        while(b!= NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }
    void Swap(int i,int j)
    {
        node *temp=head;
        int index1=0;
        while(index1!=i)
        {
            temp=temp->nxt;
            index1++;
        }
        int index2=i;
        node *temp2=temp;
        while(index2!=j)
        {
            temp2=temp2->nxt;
            index2++;
        }
        //cout<<temp->data<<" "<<temp2->data<<"\n";
        swap(temp->data,temp2->data);
    }
    void deleteZero()
    {
        // if(head->data==0)
        // {
        //     DeleteAtHead();
        // }
        node *temp=head;
        while(temp!=NULL)
        {
            if(head->data==0)
            {
                head=head->nxt;
                head->prv=NULL;
                delete temp;
                temp=head;
                sz--;
            }
            else if(temp->data==0)
            {
                node *prev,*next;
                prev=temp->prv;
                next=temp->nxt;
                prev->nxt=next;
                next->prv=prev;
                delete temp;
                temp=next;
                sz--;
            }
            else if(temp->data==0 && temp->nxt==NULL)
            {
                node *prev=temp->prv;
                prev->nxt=NULL;
                delete temp;
                sz--;
            }
            else
            {
                temp=temp->nxt;
            }
        }
    }
    ~DoublyLinkedList()
    {

    }
};


int main()
{
    DoublyLinkedList dl;
    dl.InsertAtHead(2);
    dl.InsertAtHead(0);
    dl.InsertAtHead(0);
    dl.InsertAtHead(5);
    dl.InsertAtHead(6);
    dl.InsertAtHead(0);
    dl.Traverse();
    dl.Swap(1,4);
    dl.deleteZero();
    dl.Traverse();
    dl.Reverse();
    return 0;
}