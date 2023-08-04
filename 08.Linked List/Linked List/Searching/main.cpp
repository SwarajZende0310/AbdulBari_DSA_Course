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

Node * linearSearch(Node*p,int key)
{
    while(p)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return nullptr;
}

Node * rLinearSearch(Node *p,int key)
{
    if(p==0)
        return nullptr;
    if(key==p->data)
        return p;
    return rLinearSearch(p->next,key);
}

Node * improvedLinearSearch(Node* p,int key)
{
    //Move to front used
    Node *q=nullptr;
    while(p)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return nullptr;
}
int main()
{
    cout << "Linked List" << endl;
    int A[]={1,5,2,7,8};
    create(A,5);

    display(first);
    Node* p=improvedLinearSearch(first,2);
    if(p)
    {
        cout<<endl<<"key = "<<p->data<<" found at address "<<p<<endl;
    }
    else
    {
        cout<<"Key not found"<<endl;
    }
    display(first);
    return 0;
}
