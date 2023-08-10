#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node * nxt;
};

class LinkedList
{
public:
    node * head;
    node *tail;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz=0;
    }

    //Creates a new node with data = value and nxt= NULL
    node* CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    // Insert new value at Head
    void InsertAtHead(int value)
    {
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            tail=head;
            return;
        }
        //If head is not NULL
        a->nxt = head;
        head = a;
    }
    void InsertLast(int value)
    {
        sz++;
        node *a=CreateNewNode(value);
        if(head==NULL)
        {
            head=a;
            tail=head;
        }
        else
        {
            tail->nxt=a;
            tail=a;
        }
    }
    //Prints the linked list
    void Traverse()
    {
        node* a = head;
        while(a!= NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    //Search for a single value
    int SearchDistinctValue(int value)
    {
        node* a = head;
        int index = 0;
        while(a!= NULL)
        {
            if(a->data==value)
            {
                return index;
            }
            a = a->nxt;
            index++;
        }
        return -1;
    }

    //Search all possible occurrence
    void SearchAllValue(int value)
    {
        node* a = head;
        int index = 0;
        while(a!= NULL)
        {
            if(a->data==value)
            {
                cout<<value<<" is found at index "<<index<<"\n";
            }
            a = a->nxt;
            index++;
        }
    }

    //Returns number of elements in the linked list
    int getSize()
    {
        //O(1)
        return sz;


        //O(size of linked list) = O(n)
//        int sz = 0;
//        node *a = head;
//        while(a!=NULL)
//        {
//            sz++;
//            a = a->nxt;
//        }
//        return sz;
    }

    //Insert a value at the given index
    void InsertAtAnyIndex(int index, int value)
    {
        if(index <0 || index > sz)
        {
            return;
        }
        if(index==0)
        {
            InsertAtHead(value);
            return;
        }
        sz++;
        node *a = head;
        int cur_index = 0;
        while(cur_index!=index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *newnode = CreateNewNode(value);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }

    //Delete the first element of a linked list
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        sz--;
        node *a = head;
        head = a->nxt;
        delete a;
    }

    //Delete the value at the given index
    void DeleteAnyIndex(int index)
    {
        if(index <0 || index > sz-1)
        {
            return;
        }
        if(index==0)
        {
            DeleteAtHead();
            return;
        }
        sz--;
        node *a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }

    void InsertAfterValue(int value , int data)
    {
        node *a = head;
        while(a != NULL)
        {
            if(a->data == value)
            {
                break;
            }
            a = a->nxt;
        }
        if(a== NULL)
        {
            cout<<value<<" doesn't exist in linked-list.\n";
            return;
        }
        sz++;
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }

    //Print the Reverse Order from node a to last
    void ReversePrint2(node *a)
    {
        if(a==NULL)
        {
            return;
        }
        ReversePrint2(a->nxt);
        cout<<a->data<<" ";
    }
    void ReversePrint()
    {
        ReversePrint2(head);
        cout<<"\n";
    }
    int getValue(int index)
    {
        if(index<0||index>=sz)
        {
            return -1;
        }
        node *temp=head;
        int i=0;
        while(i!=index)
        {
            temp=temp->nxt;
            i++;
        }
        if(temp==NULL)
        {
            return -1;
        }
        return temp->data;
    }
    void deleteZero()
    {
        if(head->data==0)
        {
            DeleteAtHead();
        }
        node *temp=head;
        node *prev=NULL;
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                prev->nxt=temp->nxt;
                delete temp;
                temp=prev->nxt;
            }
            else
            {
                prev=temp;
                temp=temp->nxt;
            }
        }
    }
    int getOddIndexSum()
    {
        node *temp=head;
        int i=0;
        int sum=0;
        while(temp!=NULL)
        {
            if(i%2)
            {
                sum+=temp->data;
            }
            temp=temp->nxt;
            i++;
        }
        return sum;
    }
    bool hasDuplicate()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            node *temp2=temp->nxt;
            while(temp2!=NULL)
            {
                if(temp->data==temp2->data)
                {
                    return true;
                }
                temp2=temp2->nxt;
            }
            temp=temp->nxt;
        }
        return false;
    }
    ~LinkedList()
    {
        cout<<"\n\n\tProgramme End\t\n\n";
    }
};

int main()
{
    LinkedList l;
    l.InsertAtHead(0);
    l.InsertAtHead(30);
    l.InsertAtHead(10);
    l.InsertLast(0);
    l.InsertLast(5);
    l.InsertLast(0);
    l.InsertAtHead(1);
    l.Traverse();

    //l.ReversePrint();
    //l.Traverse();
    //cout<<"\n"<<l.getValue(1);
    //l.deleteZero();
    l.Traverse();
    //cout<<l.getOddIndexSum();
    if(l.hasDuplicate())
    {
        cout<<"Linked List Contains Duplicate\n";
    }

    return 0;
}