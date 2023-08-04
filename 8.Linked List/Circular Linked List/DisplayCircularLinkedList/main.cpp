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

class CircularLinkedList
{
public:
    Node *head;

    void create(int A[],int n)
    {
        Node *t,*last;
        head=new Node(A[0]);
        head->next=head;
        last=head;
        for(int i=1;i<n;i++)
        {
            t=new Node(A[i]);
            t->next=last->next;
            last->next=t;
            last=t;
        }
    }

    void display()
    {
        Node*p=head;
        do
        {
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
    }

    void RDisplay(Node *p)
    {
        static int flag=0;
        if(p!=head || flag==0)
        {
            flag=1;
            cout<<p->data<<" ";
            RDisplay(p->next);
        }
        flag=0;
    }
};
int main()
{
    cout << "Circular Linked List:" << endl;
    int B[]={1,5,9,10,15};
    CircularLinkedList l1;
    l1.create(B,5);
    l1.RDisplay(l1.head);
    return 0;
}
