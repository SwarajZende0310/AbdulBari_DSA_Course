#include <iostream>
#include<bits/stdc++.h>
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
void display()
{
    Node*p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
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

Node* middle1()
{
    Node*p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    p=first;
    int mid=(len-1)/2;
    cout<<mid<<endl;
    for(int i=0;i<mid;i++)
    {
        p=p->next;
    }
    return p;
}
Node* middle2()
{
    Node *p,*q;
    p=q=first;
    while(q)
    {
        q=q->next;
        if(q)
            q=q->next;
        if(q)
            p=p->next;
    }
    return p;
}

Node* middle3()
{
    stack<Node> s;
    Node *p=first;
    while(p)
    {
        s.push(*p);
        p=p->next;
    }
    int mid=(s.size())/2;
    for(int i=0;i<mid;i++)
    {
        s.pop();
    }
    return &s.top();
}
};
int main()
{
    cout << "Student Challenge:Finding Middle Element" << endl;
    LinkedList l1;

    l1.insertLast(1);
    l1.insertLast(2);
    l1.insertLast(3);
    l1.insertLast(4);
    l1.insertLast(5);
    l1.insertLast(6);
    l1.insertLast(7);
    l1.insertLast(8);
    l1.insertLast(9);

    l1.display();
    Node *q=l1.middle3();
    cout<<"Middle elements is "<<q->data<<endl;
    return 0;
}
