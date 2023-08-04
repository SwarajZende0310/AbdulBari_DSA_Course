#include <iostream>
#include<queue>
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

class BinaryTree
{
public:
    Node*root;

    BinaryTree(){root=nullptr;}
    void create();
    void Preorder(Node *p);
    void IterativePreorder(Node*p);
    void Inorder(Node *p);
    void IterativeInorder(Node*p);
    void Postorder(Node *p);
    void IterativePostorder(Node*p);
    void Levelorder(Node *p);
    int countNodes(Node*p);
    int NodesWith2Child(Node*p);
    int NodesWith1Child(Node*p);
    int SumofNodes(Node*p);
    int level(Node*p);
};

void BinaryTree::create()
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

void BinaryTree::Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void BinaryTree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void BinaryTree::Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void BinaryTree::IterativePreorder(Node*t)
{
    stack<Node*>st;
    while(t!=nullptr || !(st.empty()))
    {
        if(t!=nullptr)
        {
            cout<<t->data<<" ";
            st.push(t);
            t=t->lchild;
        }
        else
        {
            t=st.top();
            st.pop();
            t=t->rchild;
        }
    }
}

void BinaryTree::IterativeInorder(Node*t)
{
    stack<Node*>st;
    while(t!=nullptr || !(st.empty()))
    {
        if(t!=nullptr)
        {
            st.push(t);
            t=t->lchild;
        }
        else
        {
            t=st.top();
            st.pop();
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
}

/*void BinaryTree::IterativePostorder(Node*t)
{
    stack<Node*>st;
    Node* temp;
    while(t!=nullptr || !(st.empty()))
    {
        if(t!=nullptr)
        {
            st.push(t);
            t=t->lchild;
        }
        else
        {
            temp=st.top();
            st.pop();
            if(temp>0)
            {
                st.push(-temp);
                t=((Node*)temp)->rchild;
            }
            else
            {
                cout<<(Node*)temp->data<<" ";
                t=nullptr;
            }
        }
    }
}*/

void BinaryTree::Levelorder(Node *p)
{
    queue<Node*>q;
    cout<<p->data<<" ";
    q.push(p);

    while(!q.empty())
    {
        p=q.front();
        q.pop();

        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
}

int BinaryTree::countNodes(Node*p)
{
    if(p)
        return countNodes(p->lchild)+countNodes(p->rchild)+1;
    return 0;
}

int BinaryTree::level(Node*p)
{
    int x,y;
    if(p)
    {
        x=level(p->lchild);
        y=level(p->rchild);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}
    int BinaryTree::NodesWith2Child(Node*p)
    {
    int x,y;
    if(p)
    {
        x=NodesWith2Child(p->lchild);
        y=NodesWith2Child(p->rchild);

        if(p->lchild && p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
    }
    int BinaryTree::SumofNodes(Node*p)
    {
        int x,y;
    if(p)
    {
        x=SumofNodes(p->lchild);
        y=SumofNodes(p->rchild);
        return x+y+p->data;
    }
    return 0;
    }

    int BinaryTree::NodesWith1Child(Node*p)
    {
        if(!p)
            return 0;
        else if((p->lchild!=nullptr) ^ (p->rchild!=nullptr))
            return NodesWith1Child(p->lchild)+NodesWith1Child(p->rchild)+1;
        else
            return NodesWith1Child(p->lchild)+NodesWith1Child(p->rchild);
    }
int main()
{
    cout << "Creating Binary Tree" << endl;
    BinaryTree t1;
    t1.create();
    cout<<"Number of Nodes: "<<t1.countNodes(t1.root)<<endl;
    cout<<"Levels in Tree: "<<t1.level(t1.root)<<endl;
    cout<<"Nodes with 2 child : "<<t1.NodesWith2Child(t1.root)<<endl;
    cout<<"Sum of Nodes: "<<t1.SumofNodes(t1.root)<<endl;
    cout<<"Nodes with one child: "<<t1.NodesWith1Child(t1.root)<<endl;
    return 0;
}
