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
    node *tail;
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
            tail=head;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }
    void InsertAtLast(int data)
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
    void deleteMid()
    {
        int i=0;
        int mid=sz/2;
        node *temp=head;
        while(i!=mid)
        {
            i++;
            temp=temp->nxt;
        }
        node *prev=temp->prv;
        prev->nxt=temp->nxt;
        temp->nxt->prv=prev;
        delete temp;
    }
    int getMax()
    {
        node *temp=head;
        int mx=INT_MIN;
        while(temp!=NULL)
        {
            if(temp->data>mx)
            {
                mx=temp->data;
            }
            temp=temp->nxt;
        }
      return mx;
    }
    void deleteMax()
    {
        node *mxnode=head;
        node *curr=head;
        node *prev=NULL;
        while(curr!=NULL)
        {
            if(curr->data>mxnode->data)
            {
                mxnode=curr;
            }
            curr=curr->nxt;
        }
        node *temp=mxnode->nxt;
        int cpyMxdata=mxnode->data;
        while(temp!=NULL)
        {
            if(temp->data==cpyMxdata)
            {
                node *prev=temp->prv;
                node *next=temp->nxt;
                prev->nxt=next;
                next->prv=prev;
                delete temp;
                temp=next;
            }
            else
            {
                temp=temp->nxt;
            }
        }
        //if(mxnode->prv!=NULL && mxnode->nxt!=NULL)
        {
            node *prev1=mxnode->prv;
            node *next1=mxnode->nxt;
            prev1->nxt=next1;
            next1->prv=prev1;
            delete mxnode;
        }
        // else if(mxnode->prv==NULL)
        // {
        //     head=head->nxt;
        //     head->prv=NULL;
        //     delete mxnode;
        // }
        // else if(mxnode->nxt==NULL)
        // {
        //     tail=mxnode->prv;
        //     tail->nxt=NULL;
        //     delete mxnode;
        // }
        
    }
    ~DoublyLinkedList()
    {
        cout<<"\n\n\tProgramme End\t\n\n";
    }
};


int main()
{
    DoublyLinkedList dl;
    dl.InsertAtLast(10);
    dl.InsertAtLast(5);
    dl.InsertAtLast(1);
    dl.InsertAtLast(10);
    dl.InsertAtLast(2);
    dl.InsertAtLast(10);
    dl.InsertAtLast(5);
    dl.InsertAtLast(10);
    dl.InsertAtLast(7);
    //dl.InsertAtLast(10);
    //dl.Traverse();
    //dl.Insert(2,10);

    //dl.Traverse();

    //dl.Reverse();
    //dl.Traverse();
    //dl.deleteMid();
    dl.Traverse();
    //cout<<dl.getMax()<<"\n";
    dl.deleteMax();
    dl.Traverse();
    return 0;
}