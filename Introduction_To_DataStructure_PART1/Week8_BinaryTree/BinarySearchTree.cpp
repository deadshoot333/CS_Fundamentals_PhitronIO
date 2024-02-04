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
    void Delete(int value)
    {
        Node *prev=NULL;
        Node *curr=root;
        while(curr!=NULL)
        {
            if(value<curr->value)
            {
                prev=curr;
                curr=curr->left;
            }
            else if(value>curr->value)
            {
                prev=curr;
                curr=curr->right;
            }
            else
            {
                break;
            }
        }
        if(curr==NULL)
        {
            cout<<"Value not in the tree\n";
            return;
        }
        // curr having no child
        if(curr->left==NULL && curr->right==NULL)
        {
            if(prev->left!=NULL && prev->left->value==curr->value)
            {
                prev->left=NULL;
            }
            else if(prev->right!=NULL && prev->right->value==curr->value)
            {
                prev->right=NULL;
            }
            delete curr;
            return;
        }
        //
        //curr having one child in left
        if(curr->left!=NULL && curr->right==NULL)
        {
            if(prev->left->value==curr->value)
            {
                prev->left=curr->left;
            }
            else
            {
                prev->right=curr->left;
            }
            delete curr;
            return;
        }//curr having one child in right
        if(curr->left==NULL && curr->right!=NULL)
        {
            if(prev->left->value==curr->value)
            {
                prev->left=curr->right;
            }
            else
            {
                prev->right=curr->right;
            }
            delete curr;
            return;
        }
        //
        //curr having two child
        Node *tmp=curr->right;
        while(tmp->left!=NULL)
        {
            tmp=tmp->left;
        }
        int saved=tmp->value;
        Delete(saved);
        curr->value=saved;
        //
    }

};

int main()
{
    BST bst;
    bst.Insertion(10);
    bst.Insertion(5);
    bst.Insertion(6);
    bst.Insertion(11);
    bst.Insertion(17);
    bst.Insertion(18);
    bst.BFS();
    if(bst.Search(8))
    {
        cout<<"Item found\n";
    }
    else
    {
        cout<<"Item not found\n";
    }
    bst.Delete(6);
    bst.BFS();
    cout<<"\nAfter Deleting 11\n";
    bst.Delete(11);
    bst.BFS();
    cout<<"\nAfter Deleting 10\n";
    bst.Delete(10);
    bst.BFS();

}