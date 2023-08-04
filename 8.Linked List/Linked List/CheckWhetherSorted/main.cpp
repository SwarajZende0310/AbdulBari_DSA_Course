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

bool CheckWhetherSorted()
{
    int x=-32768;
    Node*p=first;
    while(p)
    {
        if(p->data < x)
        {
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
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
    if(CheckWhetherSorted())
    {
        cout<<"Linked list sorted"<<endl;
    }
    else
    {
        cout<<"Linked list unsorted"<<endl;
    }
    return 0;
}
