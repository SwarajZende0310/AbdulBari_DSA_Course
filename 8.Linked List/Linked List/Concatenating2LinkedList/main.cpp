#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node * next;

    Node(){}
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};

class LinkedList:public Node
{
public:
Node *first;
Node *last;
LinkedList()
{
 first=nullptr;
 last=nullptr;
}
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

void concat(LinkedList l)
{
    Node *p=first;
    while(p->next)
    {
        p=p->next;
    }
    p->next=l.first;
}
};

int main()
{
    cout << "Linked List l1:" << endl;
    LinkedList l1;
    l1.insertLast(8);
    l1.insertLast(5);
    l1.insertLast(15);
    l1.insertLast(20);
    l1.insertLast(38);
    l1.display(l1.first);
    cout<<endl;

    LinkedList l2;
    l2.insertLast(50);
    l2.insertLast(60);
    l2.insertLast(70);
    cout << "Linked List l2:" << endl;
    l2.display(l2.first);
    cout<<endl;

    cout<<"Concatenated Linked List: "<<endl;
    l1.concat(l2);
    l1.display(l1.first);
    return 0;
}
