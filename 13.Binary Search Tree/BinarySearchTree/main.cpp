#include <iostream>
#include <queue>
#include<stack>
using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;

    Node(int x)
    {
        data=x;
        lchild=rchild=nullptr;
    }
};

class BinarySearchTree
{
public:
    Node*root;

    BinarySearchTree(){root=nullptr;}
    void create();
    void Insert(Node*t,int key);
    Node* RInsert(Node*p,int key);
    Node* RSearch(Node*t,int key);
    Node* Search(Node*t,int key);
    void Inorder(Node*p);
    Node*Delete(Node*p,int key);
    int Height(Node*p);
    Node*InPre(Node*p);
    Node*InSucc(Node*p);
    void createFromPreorder(int pre[],int n);
};

void BinarySearchTree::create()
{
    Node*p,*t;
    int x;
    cout<<"Enter the value of Root node:"<<endl;
    cin>>x;
    queue<Node*>q;

    root=new Node(x);
    q.push(root);

    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"Enter the Left Child of "<<p->data<<" :"<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            p->lchild=t;
            q.push(t);
        }

        cout<<"Enter the Right Child of "<<p->data<<" :"<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            p->rchild=t;
            q.push(t);
        }
    }
}

Node* BinarySearchTree::RSearch(Node*t,int key)
{
    if(!t)
        return nullptr;
    if(key==t->data)
        return t;
    else if(key<t->data)
        return RSearch(t->lchild,key);
    else
        return RSearch(t->rchild,key);
}

Node* BinarySearchTree::Search(Node*t,int key)
{
    while(t)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return nullptr;
}

Node * BinarySearchTree::RInsert(Node*p,int key)
{
    Node*t;
    if(p==nullptr)
    {
        t=new Node(key);
        return t;
    }
    else if(key<p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}

void BinarySearchTree::Insert(Node*t,int key)
{
    Node *r=nullptr;
    Node*p;
    if(root==nullptr)
    {
        root=new Node(key);
        return;
    }
    while(t)
    {
        if(key==t->data)
            return;
        else if(key < t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    p=new Node(key);
    if(p->data<r->data)
    {
        r->lchild=p;
    }
    else
    {
        r->rchild=p;
    }
}

void Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

int BinarySearchTree::Height(Node*p)
{
    int x,y;
    if(!p)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);

    return x>y?x+1:y+1;
}

Node* BinarySearchTree::InPre(Node*p)
{
    while(p && p->rchild!=nullptr)
    {
        p=p->rchild;
    }
    return p;
}

Node* BinarySearchTree::InSucc(Node*p)
{
    while(p && p->lchild!=nullptr)
    {
        p=p->lchild;
    }
    return p;
}

Node* BinarySearchTree::Delete(Node*p,int key)
{
    Node*q;
    //Base cases
    if(!p)
        return nullptr;
    if(p->lchild==nullptr && p->rchild==nullptr)
    {
        if(p==root)
            root=nullptr;
        delete p;
        return nullptr;
    }

    //Similar to Searching

    if(key < p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

void BinarySearchTree :: createFromPreorder(int pre[],int n)
{
    stack<Node*>st;
    Node*p,*t;
    int i=0;
    root=new Node(pre[i++]);
    p=root;

    while(i<n)
    {
        if(pre[i] < p->data)
        {
            t=new Node(pre[i++]);
            p->lchild=t;
            st.push(p);
            p=t;
        }
        else
        {
            if(pre[i]>p->data && pre[i]<st.top()->data)
            {
                t=new Node(pre[i++]);
                p->rchild=t;
                p=t;
            }
            else
            {
                p=st.top();
                st.pop();
            }
        }
    }
}

int main()
{
    cout << "Creating Binary Search Tree: " << endl;
    BinarySearchTree t1;
    //t1.create();
    //Node*s=t1.RSearch(t1.root,25);

    return 0;
}
