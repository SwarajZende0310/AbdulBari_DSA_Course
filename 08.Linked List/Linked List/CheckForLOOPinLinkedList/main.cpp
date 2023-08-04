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

bool isLoop()
{
    Node *p,*q;
    p=q=first;

    do
    {
        p=p->next;
        q=q->next;
        if(q)
            q=q->next;
    }while(p && q && p!=q);

    if(p==q)
        return true;
    else
        return false;
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

    //Looping Linked List
    Node *t1,*t2;
    t1=l1.first->next->next;
    t2=l1.last;
    t2->next=t1;


    if(l1.isLoop())
    {
        cout<<"It is a Looped Linked List"<<endl;
    }
    else
    {
        cout<<"It is a Linear Linked List"<<endl;
    }
    return 0;
}
