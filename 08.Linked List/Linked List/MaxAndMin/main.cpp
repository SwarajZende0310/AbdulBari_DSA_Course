#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node * next;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
Node *first=nullptr;
void create(int A[],int n)
{
    Node *t,*last;
    first=new Node(A[0]);
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node(A[i]);
        last->next=t;
        last=t;
    }
}

void display(Node* p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int maxnode(Node *p)
{
    int m=-32768;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}

int rmaxnode(Node *p)
{
    int x=0;
    if(p==0)
        return -32768;//Minimum integer number
    x=rmaxnode(p->next);
    if(x > p->data)
        return x;
    return p->data;
}
int minnode(Node *p)
{
    int m=32767;
    while(p)
    {
        if(p->data < m)
            m=p->data;
        p=p->next;
    }
    return m;
}

int rminnode(Node *p)
{
    int x=0;
    if(p==0)
        return 32767;//Maximum integer number
    x=rmaxnode(p->next);
    if(x < p->data)
        return x;
    return p->data;
}
int main()
{
    cout << "Maximum and Minimum Linked List" << endl;
    int A[]={1,5,2,7,8};
    create(A,5);
    display(first);
    cout<<endl;
    cout<<"Maximum in Linked list is "<<rmaxnode(first)<<endl;
    cout<<"Minimum in Linked List is "<<rminnode(first)<<endl;
    return 0;
}


