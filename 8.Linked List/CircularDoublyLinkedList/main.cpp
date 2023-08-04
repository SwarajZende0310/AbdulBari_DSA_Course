#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(){next=prev=nullptr;}
    Node(int x)
    {
        data=x;
        next=prev=nullptr;
    }
};

class CircularDoublyLinkedList
{
private:
    Node *head;
    Node *last;
public:
    void create(int A[],int n)
    {
        Node *t=new Node(A[0]);
        head=last=t;
        t->prev=t->next=t;

        for(int i=1;i<n;i++)
        {
            t=new Node(A[i]);
            last->next=t;
            t->prev=last;
            last=t;
            last->next=head;
            head->prev=last;
        }
    }

    void display()
    {
        Node *p=head;
        do
        {
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
        cout<<endl;
    }

    void Insert(int pos,int x)
    {
        Node *t=new Node(x);

        if(pos==0)
        {
            if(head==nullptr)
            {
                head=last=t;
                t->next=t->prev=t;
            }
            else
            {
                last->next=t;
                t->prev=last;
                t->next=head;
                head->prev=t;
                head=t;
            }
        }
        else
        {
            Node *p=head;
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            t->next=p->next;
            t->prev=p;
            p->next=t;
            p->next->prev=t;
            if(t->next==head)
            {
                last=t;
            }
        }
    }

    int Delete(int pos)
    {
        int x;
        if(pos==1)
        {
            last->next=head->next;
            head->next->prev=last;
            x=head->data;
            delete head;
            head=last->next;
        }
        else
        {
            Node *p=head;
            for(int i=0;i<pos-2;i++)
            {
                p=p->next;
            }
            Node*q=p->next;
            if(q==last)
            {
                last=p;
            }
            p->next=q->next;
            q->next->prev=p;
            x=q->data;
            delete q;
        }
        return x;
    }
};

int main()
{
    cout << "Circular Doubly Linked List: " << endl;
    CircularDoublyLinkedList l1;
    int B[]={1,5,9,7,6};
    l1.create(B,5);
    l1.display();

    cout<<"Circular Doubly Linked List after Insertion :"<<endl;
    l1.Insert(5,20);
    l1.Insert(0,21);
    l1.display();

    cout<<"Circular Doubly Linked List after Deletion :"<<endl;
    l1.Delete(7);
    l1.Delete(1);
    l1.display();
    return 0;
}
