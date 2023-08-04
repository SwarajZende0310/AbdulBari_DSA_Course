#include <iostream>

using namespace std;

class Node
{
public:
    Node* prev;
    int data;
    Node *next;

    Node()
    {
        prev=next=nullptr;
    }
    Node(int x)
    {
        data=x;
        prev=next=nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *first;
    Node *last;

    void create(int A[],int n)
    {
        Node*t;
        first=new Node(A[0]);
        last=first;

        for(int i=1;i<n;i++)
        {
            t=new Node(A[i]);
            t->next=last->next;
            t->prev=last;
            last->next=t;
            last=t;
        }
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

    int len()
    {
        int len=0;
        Node *p=first;
        while(p)
        {
            len++;
            p=p->next;
        }
        return len;
    }

    void Insert(int pos,int x)
    {
        Node *t;
        if(pos==0)
        {
            t=new Node(x);
            t->next=first;
            first->prev=t;
            first=t;
        }
        else
        {
            Node*p=first;
            t=new Node(x);
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            t->next=p->next;
            t->prev=p;
            if(p->next)
            {
                (p->next)->prev=t;
            }
            p->next=t;
        }
    }

    int Delete(int pos)
    {
        Node *p=first;
        int x;
        if(pos==1)
        {
            first=first->next;
            x=p->data;
            delete p;
            if(first)
                first->prev=nullptr;
        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            (p->prev)->next=p->next;
            if(p->next)
                (p->next)->prev=p->prev;
            x=p->data;
            delete p;
        }
        return x;
    }

    void Reverse()
    {
        Node *p=first;
        Node*temp;

        while(p)
        {
            //Swapping prev and next
            temp=p->next;
            p->next=p->prev;
            p->prev=temp;

            //Moving fwd in list
            p=p->prev; //Bcoz swapped

            //If last element
            if(p!=nullptr && p->next==nullptr)
            {
                first=p;//Make it First
            }
        }
    }
};
int main()
{
    cout << "Doubly Linked List:" << endl;
    int A[]={3,5,9,12,4,75};
    DoublyLinkedList l1;
    l1.create(A,6);
    l1.display();

    cout<<"Linked List after Insertion: "<<endl;
    l1.Insert(6,90);
    l1.display();

    cout<<"Linked List After Deletion: "<<endl;
    l1.Delete(7);
    l1.display();

    cout<<"Linked List After Reversing: "<<endl;
    l1.Reverse();
    l1.display();
    return 0;
}
