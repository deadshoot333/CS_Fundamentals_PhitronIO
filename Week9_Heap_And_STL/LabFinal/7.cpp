#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node *left;
    Node *right;
};

class BST
{
    public:
    Node *root;
    BST()
    {
        root=NULL;
    }

    Node *CreateNewNode(int value)
    {
        Node *newNode=new Node;
        newNode->value=value;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }

    void BFS()
    {
        if(root==NULL)
        {
            cout<<"Tree empty\n";
            return;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node *king=q.front();
            q.pop();
            int l=rand(),r=rand() ;
            if(king->left!=NULL)
            {
                q.push(king->left);
                l=king->left->value;
            }
            if(king->right!=NULL)
            {
                q.push(king->right);
                r=king->right->value;
            }
            cout<<"Node= "<<king->value<<" Left= "<<l<<" Right= "<<r<<"\n";
        }
    }

    void Insertion(int value)
    {
        Node *newNode=CreateNewNode(value);
        if(root==NULL)
        {
            root=newNode;
            return;
        }
        Node *curr,*prev;
        curr=root;
        prev=NULL;
        while(curr!=NULL)
        {
            if(newNode->value>curr->value)
            {
                prev=curr;
                curr=curr->right;
            }
            else
            {
                prev=curr;
                curr=curr->left;
            }
        }
        if(newNode->value>prev->value)
        {
            prev->right=newNode;
        }
        else
        {
            prev->left=newNode;
        }
    }
    bool Search(int value)
    {
        Node *curr=root;
        while(curr!=NULL)
        {
            if(value>curr->value)
            {
                curr=curr->right;
            }
            else if(value<curr->value)
            {
                curr=curr->left;
            }
            else 
            {
                return true;
            }
        }
        return false;
    }

};

int main()
{
    BST bst;
    bst.Insertion(10);
    bst.Insertion(20);
    bst.Insertion(25);
    bst.Insertion(50);
    bst.Insertion(8);
    bst.Insertion(9);
    cout<<bst.Search(10)<<"\n"; //1
    cout<<bst.Search(9)<<"\n"; //1
    cout<<bst.Search(20)<<"\n"; //1
    cout<<bst.Search(60)<<"\n"; //0

}