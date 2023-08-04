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


Node* Intersection(LinkedList l2)
{
    stack<Node> s1;
    stack<Node> s2;

    //Copying 1st Linked List in s1
    Node *p=first;
    while(p)
    {
        s1.push(*p);
        p=p->next;
    }

    //Copying 2nd Linked List in s2
    Node *q=l2.first;
    while(q)
    {
        s2.push(*q);
        q=q->next;
    }

    Node *temp;
    while((&s1.top())->data==(&s2.top())->data)
    {
        temp=&s1.top();
        s1.pop();
        s2.pop();
    }
    return temp;
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

    cout<<"Linked List l1:"<<endl;
    l1.display();

    LinkedList l2;
    l2.insertLast(99);
    l2.insertLast(98);
    l2.insertLast(97);
    l2.display();
    Node *p=l2.first;
    (p->next->next)->next=l1.first->next->next->next;
    l2.display();
    Node *q=l1.Intersection(l2);
    cout<<"Intersection is "<<q->data<<endl;
    return 0;
}
