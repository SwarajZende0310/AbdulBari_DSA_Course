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

int icount(Node* p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

int rcount(Node * p)
{
    if(p)
    {
        return rcount(p->next)+1;
    }
    return 0;
}
int main()
{
    cout << "Counting Nodes" << endl;
    int A[]={5,3,7,9,10};
    create(A,5);

    cout<<"Number of nodes = "<<rcount(first);
    return 0;
}
