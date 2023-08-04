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

Node *first=nullptr,*last=nullptr;

void insertLast(int x)
{
    Node *t=new Node(x);
    if(first==0)
    {
        first=last=t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}

void display(Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void ReverseElements()
{
    Node *p=first;
    int i=0;
    int A[10];
    while(p)
    {
        A[i]=p->data;
        i++;
        p=p->next;
    }
    p=first;
    i--;
    while(p)
    {
        p->data=A[i];
        i--;
        p=p->next;
    }
}

void ReverseLinks()
{
    Node *p=first;
    Node *q=nullptr;
    Node *r=nullptr;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void ReverseRecursion(Node *q,Node *p)
{
    if(p)
    {
        ReverseRecursion(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}
int main()
{
    cout << "Linked List:" << endl;
    insertLast(8);
    insertLast(5);
    insertLast(15);
    insertLast(20);
    insertLast(38);
    display(first);
    cout<<endl<<"Linked List after Reversing :"<<endl;
    ReverseRecursion(nullptr,first);
    display(first);
    return 0;
}
