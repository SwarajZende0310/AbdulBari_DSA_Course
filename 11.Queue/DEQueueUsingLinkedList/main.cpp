#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(){}
    Node(int x)
    {
        data=x;
        next=nullptr;
    }
};

class DEQueue
{
public:
    Node*Front=nullptr;
    Node*rear=nullptr;

    void frontEnqueue(int x)
    {
        Node*t=new Node(x);
        if(!t)
            cout<<"DEQueue is Full"<<endl;
        else
        {
            t->next=Front;
            Front =t;
        }
    }

    void rearEnqueue(int x)
    {
        Node*t=new Node(x);
        if(!t)
        {
            cout<<"DEQueue is Full"<<endl;
        }
        else
        {
            if(!Front)
            {
                Front=rear=t;
            }
            else
            {
                rear->next=t;
                rear=t;
            }
        }
    }

    int frontDequeue()
    {
        Node*p;
        int x=-1;
        if(!Front)
            cout<<"DEQueue is Empty"<<endl;
        else
        {
            p=Front;
            Front=Front->next;
            x=p->data;
            delete p;
        }
        return x;
    }

    int rearDequeue()
    {
        Node *p;
        int x=-1;
        if(!Front)
            cout<<"DEQueue is Empty"<<endl;
        else
        {
            while(p->next->next)
            {
                p=p->next;
            }
            rear=p;
            x=p->next->data;
            delete p;
        }
        return x;
    }

    void display()
    {
        Node*p=Front;
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
int main()
{
    cout << "DEQueue using Linked List" << endl;
    DEQueue q1;
    q1.rearEnqueue(1);
    q1.rearEnqueue(2);
    q1.rearEnqueue(3);
    q1.rearEnqueue(4);
    q1.rearEnqueue(5);
    q1.rearEnqueue(6);
    q1.display();

    q1.frontDequeue();
    q1.display();

    q1.frontEnqueue(7);
    q1.display();

    return 0;
}
