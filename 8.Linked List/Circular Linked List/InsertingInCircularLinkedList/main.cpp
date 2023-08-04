#include<iostream>

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

    CircularLinkedList()
    {
        head=nullptr;
    }
    int length()
    {
        Node*p=head;
        int len=0;
        do
        {
            len++;
            p=p->next;
        }while(p!=head);
        return len;
    }

    void display()
    {
        Node*p=head;
        do
        {
            cout<<p->data<<" ";;
            p=p->next;
        }while(p!=head);
    }
    void Insert(int pos,int x)
    {
        Node *p=head;
        Node *t;
        /*int l=length();
        //Validating pos
        if(pos<0 || pos>l)
        {
            return;
        }*/
        if(pos==0)
        {
            t=new Node(x);
            if(head==nullptr)
            {
                head=t;
                head->next=head;
            }
            else
            {
                while(p->next!=head)
                {
                    p=p->next;
                }
                p->next=t;
                t->next=head;
                head=t;
            }
        }
        else
        {
            t=new Node(x);
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
    }
};
int main()
{
    cout << "Inserting in Circular Linked List: " << endl;
    CircularLinkedList l1;
    l1.Insert(0,1);
    l1.Insert(1,5);
    l1.Insert(2,10);
    l1.Insert(3,9);
    l1.Insert(4,23);

    l1.display();
    return 0;
}
