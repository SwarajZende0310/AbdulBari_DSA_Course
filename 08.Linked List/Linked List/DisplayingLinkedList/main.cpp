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
Node *first=nullptr;
void create(int A[],int n)
{
    Node *t,*last;
    first=new Node(A[0]);
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node(A[i]);
        last->next=t;
        last=t;
    }
}

void display(Node* p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void Rdisplay(Node*p)//Recursive
{
    if(p)
    {
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
}

void RRdisplay(Node*p)//Recursive Reverse
{
    if(p)
    {
        RRdisplay(p->next);
        cout<<p->data<<" ";
    }
}
int main()
{
    cout << "Displaying Linked List" << endl;
    int A[]={1,5,2,7,8};
    create(A,5);
    RRdisplay(first);
    return 0;
}
