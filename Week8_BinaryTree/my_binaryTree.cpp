#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int id;
    Node *left;
    Node *right;
    Node *parent;
};

class BinaryTree
{
    public:
    bool found_flag=false;
    Node *root;
    BinaryTree()
    {
        root=NULL;
    }
    Node *CreateNewNode(int value)
    {
        Node *newitem=new Node;
        newitem->id=value;
        newitem->left=NULL;
        newitem->right=NULL;
        newitem->parent=NULL;
        return newitem;
    }
    void Insertion(int id)
    {
        Node *newitem=CreateNewNode(id);
        queue<Node *>q;
        if(this->root==NULL)
        {
            root=newitem;
            return;
        }
        q.push(root);
        while(!q.empty())
        {
            Node *king=q.front();
            q.pop();
            if(king->left!=NULL)
            {
                q.push(king->left);
            }
            else
            {
                king->left=newitem;
                newitem->parent=king;
                return;
            }
            if(king->right!=NULL)
            {
                q.push(king->right);
            }
            else
            {
                king->right=newitem;
                newitem->parent=king;
                return;
            }
        }
    }
    void BFS()
    {
        if(root==NULL)
        {
            return;
        }
        queue<Node *>q;
        q.push(root);
        while (!q.empty())
        {
            Node *king=q.front();
            q.pop();
            int leftID,rightID,parentID;
            if(king->left!=NULL)
            {
                q.push(king->left);
                leftID=king->left->id;
            }
            if(king->right!=NULL)
            {
                q.push(king->right);
                rightID=king->right->id;
            }
            if(king->parent!=NULL)
            {
                parentID=king->parent->id;
            }
            cout<<"---------------------------\n";
            cout<<"The Node is = "<<king->id<<"\n";
            if(king->parent!=NULL)
            {
                cout<<"Parent is = "<<parentID<<"\n";
            }
            cout<<"Left Child is = "<<leftID<<"\n";
            cout<<"Right Child is = "<<rightID<<"\n";
        }
        
    }
    void DFS(Node *a)
    {
        if(a==NULL)
        {
            return;
        }
        cout<<a->id<<"\n";
        DFS(a->left);
        DFS(a->right);
    }
    void Inorder(Node *a)
    {
        if(a==NULL)
        {
            return;
        }
        Inorder(a->left);
        cout<<a->id<<"\n";
        Inorder(a->right);
    }
    void Postorder(Node *a)
    {
        if(a==NULL)
        {
            return;
        }
        Postorder(a->left);
        Postorder(a->right);
        cout<<a->id<<"\n";
    }
    void Preorder(Node *a)
    {
        if(a==NULL)
        {
            return;
        }
        cout<<a->id<<"\n";
        Preorder(a->left);
        Preorder(a->right);
    }
    void Search(int value,Node *a)
    {
        if(a==NULL)
        {
            return;
        }
        if(a->id==value)
        {
            this->found_flag=true;
            return;    
        }
        Search(value,a->left);
        Search(value,a->right);
    }
};
int main()
{
    BinaryTree bt;
    bt.Insertion(20);
    bt.Insertion(10);
    bt.Insertion(22);
    bt.Insertion(5);
    bt.Insertion(12);
    bt.Insertion(21);
    bt.Insertion(25);
    bt.Insertion(3);
    bt.Insertion(15);
    bt.BFS();
    cout<<"DFS--->\n";
    bt.DFS(bt.root);
    cout<<"Inorder-->\n";
    bt.Inorder(bt.root);
    cout<<"Preorder-->\n";
    bt.Preorder(bt.root);
    cout<<"Postorder-->\n";
    bt.Postorder(bt.root);
    int number;
    cout<<"Enter the number to be searched = ";
    cin>>number;
    bt.Search(number,bt.root);
    if(!bt.found_flag)
    {
        cout<<"Item not found!!!\n";
    }
    else
    {
        cout<<"Item Found\n";
    }   

}