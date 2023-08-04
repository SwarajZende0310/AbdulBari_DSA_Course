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

int sum(Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int rsum(Node *p)
{
    if(p==0)
    {
        return 0;
    }
    return rsum(p->next)+p->data;
}
int main()
{
    cout << "Sum of All the Nodes:" << endl;
    int A[]={5,3,7,9,10};
    create(A,5);

    cout<<"Sum of All the Nodes is "<<rsum(first)<<endl;
    return 0;
}
