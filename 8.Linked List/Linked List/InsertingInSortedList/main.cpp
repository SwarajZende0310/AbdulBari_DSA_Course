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


void sortedInsert3(int x)
{
    Node *p=first;//Using only 3 pointers
    Node *q=nullptr;
    Node *t=new Node(x);
    if(x<p->data)
    {
        t->next=first;
        first=t;
    }
    else
    {
        while(x>p->data && p)
        {
            q=p;
            p=p->next;
        }
        t->next=q->next;
        q->next=t;
    }
}

void sortedInsert2(int x)
{
    Node *p=first;//Using only 2 pointers
    Node *t=new Node(x);
    if(x<p->data)
    {
        t->next=first;
        first=t;
    }
    else
    {
        while(x>(p->next)->data && p)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int main()
{
    cout << "Linked List:" << endl;
    insertLast(3);
    insertLast(5);
    insertLast(15);
    insertLast(20);
    insertLast(38);
    display(first);

    cout<<endl;
    sortedInsert3(4);
    display(first);
    return 0;
}
