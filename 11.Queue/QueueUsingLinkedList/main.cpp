#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node*next;

    Node(){}
    Node(int x)
    {
        data=x;
        next=nullptr;
    }
};

class Queue
{
public:
    Node*Front=nullptr;
    Node*rear=nullptr;

    bool isEmpty()
    {
        if(Front==nullptr)
            return true;
        return false;
    }
    bool isFull()
    {
        Node *t=new Node;
        if(t==nullptr)
        {
            return true;
        }
        return false;
    }

    void enqueue(int x)
    {
        Node*t=new Node(x);
        if(t==nullptr)
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            if(Front==nullptr)
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

    int dequeue()
    {
        int x=-1;
        Node*p;
        if(Front==nullptr)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            p=Front;
            Front=Front->next;
            x=p->data;
            delete p;
        }
        return x;

    }

    void display()
    {
        Node *p=Front;
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
    cout << "Queue using Linked List" << endl;
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();

    q1.dequeue();
    q1.display();
    return 0;
}
