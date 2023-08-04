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

void mergeLinkedList(LinkedList l)
{
    Node *tfirst;
    Node *last;
    if(first->data < l.first->data)
    {
        tfirst=last=first;
        first=first->next;
        last->next=nullptr;
    }
    else
    {
        tfirst=last=l.first;
        l.first=l.first->next;
        last->next=nullptr;
    }
    while(first && l.first)
    {
        if(first->data < l.first->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=nullptr;
        }
        else
        {
            last->next=l.first;
            last=l.first;
            l.first=l.first->next;
            last->next=nullptr;
        }
    }
    if(first)
    {
        last->next=first;
    }
    else if(l.first)
    {
        last->next=l.first;
    }
    first=tfirst;
}
};

int main()
{
    cout << "Linked List l1:" << endl;
    LinkedList l1;
    l1.insertLast(3);
    l1.insertLast(5);
    l1.insertLast(15);
    l1.insertLast(20);
    l1.insertLast(38);
    l1.display(l1.first);
    cout<<endl;

    LinkedList l2;
    l2.insertLast(12);
    l2.insertLast(21);
    l2.insertLast(40);
    cout << "Linked List l2:" << endl;
    l2.display(l2.first);
    cout<<endl;

    cout<<"Merged Linked List: "<<endl;
    l1.mergeLinkedList(l2);
    l1.display(l1.first);
    return 0;
}
