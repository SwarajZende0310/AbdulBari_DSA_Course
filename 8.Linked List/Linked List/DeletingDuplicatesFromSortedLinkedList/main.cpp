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

void DeletingDuplicates()
{
    Node *p=first;
    Node *q=p->next;

    while(q)
    {
        if(p->data == q->data)
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
        else
        {
            p=q;
            q=q->next;
        }
    }
}
int main()
{
    cout << "Linked List:" << endl;
    insertLast(3);
    insertLast(3);
    insertLast(5);
    insertLast(8);
    insertLast(8);
    display(first);

    cout<<endl;
    DeletingDuplicates();
    cout<<"Linked list after deletion of duplicates:"<<endl;
    display(first);
    return 0;
}
