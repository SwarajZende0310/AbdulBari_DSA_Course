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

int Delete(int pos)
{
    Node *p,*q;
    int x=-1;
    if(pos==1)
    {
        p=first;
        x=first->data;
        first=first->next;
        delete p;
    }
    else
    {
        p=first;
        q=nullptr;
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
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

    cout<<endl;
    Delete(3);
    cout<<"Linked list after deletion:"<<endl;
    display(first);
    return 0;
}
