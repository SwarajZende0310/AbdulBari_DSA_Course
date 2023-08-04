#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(){next=nullptr;}
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
int main()
{
    cout << "Stack using Linked List" << endl;
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();
    s1.pop();
    s1.display();
    return 0;
}
