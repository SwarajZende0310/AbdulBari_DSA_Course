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
class Stack
{
public:
    Node*top=nullptr;

    //Stack(){top==nullptr;}
    bool isEmpty()
    {
        if(top)
        {
            return false;
        }
        return true;
    }
    bool isFull()
    {
        Node*t=new Node;
        if(t)
        {
            return false;
        }
        delete t;
        return true;
    }

    void push(int x)
    {
        Node*t=new Node(x);
        if(!t)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            t->next=top;
            top=t;
        }
    }
    int pop()
    {
        int x=-1;
        if(!top)
            cout<<"Stack Underflow"<<endl;
        else
        {
            Node*p=top;
            top=top->next;
            x=p->data;
            delete p;
        }
        return x;
    }
    int peek(int pos)
    {
        Node *p=top;
        for(int i=0;i<pos-1 && p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            return p->data;
        }
        else
        {
            return -1;
        }
    }
    int StackTop()
    {
        if(top)
            return top->data;
        return -1;
    }

    void display()
    {
        Node*p=top;
        while(p!=nullptr)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};

class Queue
{
public:
    Stack s1;
    Stack s2;

    void Enqueue(int x)
    {
        s1.push(x);
    }
    int dequeue()
    {
        int x=-1;
        if(s2.isEmpty())
        {
            if(s1.isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return x;
            }
            else
            {
                while(!s1.isEmpty())
                    s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

    void display()
    {
        s2.display();
        s1.display();
    }
};
int main()
{
    cout << "Queue using 2 Stack" << endl;
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Enqueue(5);
    q1.Enqueue(6);

    q1.display();

    q1.dequeue();
    q1.display();
    return 0;
}
