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

void Insert(int pos,int x)
{
    Node *p,*t;
    if(pos==0)
    {
        t=new Node(x);
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        p=first;
        for(int i=0;i<(pos-1) && p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            t=new Node(x);
            t->next=p->next;
            p->next=t;
        }
    }
}
int main()
{
    cout << "Linked List:" << endl;
    int A[]={1,5,2,7,8};
    create(A,5);
    display(first);
    Insert(3,199);
    cout<<endl<<"Linked List After Insertion:"<<endl;
    display(first);
    return 0;
}
