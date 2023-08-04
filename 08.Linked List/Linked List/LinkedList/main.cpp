#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node * next;
    Node(){}
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
/*Node *first=nullptr;
Node *last=nullptr;
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
}*/
class LinkedList:public Node
{
public:
Node *first;
Node *last;
LinkedList()
{
 first=nullptr;
 last=nullptr;
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

int maxnode(Node *p)
{
    int m=-32768;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}

int rmaxnode(Node *p)
{
    int x=0;
    if(p==0)
        return -32768;//Minimum integer number
    x=rmaxnode(p->next);
    if(x > p->data)
        return x;
    return p->data;
}
int minnode(Node *p)
{
    int m=32767;
    while(p)
    {
        if(p->data < m)
            m=p->data;
        p=p->next;
    }
    return m;
}

int rminnode(Node *p)
{
    int x=0;
    if(p==0)
        return 32767;//Maximum integer number
    x=rmaxnode(p->next);
    if(x < p->data)
        return x;
    return p->data;
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

void Insert(int pos,int x)
{
    Node *p,*t;
    if(pos==0)
    {
        t=new Node(x);
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        p=first;
        for(int i=0;i<(pos-1) && p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            t=new Node(x);
            t->next=p->next;
            p->next=t;
        }
    }
}

void insertLast(int x)
{
    Node *t=new Node(x);
    if(first==0)
    {
        first=last=t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}


void sortedInsert3(int x)
{
    Node *p=first;//Using only 3 pointers
    Node *q=nullptr;
    Node *t=new Node(x);
    if(x<p->data)
    {
        t->next=first;
        first=t;
    }
    else
    {
        while(x>p->data && p)
        {
            q=p;
            p=p->next;
        }
        t->next=q->next;
        q->next=t;
    }
}

void sortedInsert2(int x)
{
    Node *p=first;//Using only 2 pointers
    Node *t=new Node(x);
    if(x<p->data)
    {
        t->next=first;
        first=t;
    }
    else
    {
        while(x>(p->next)->data && p)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

int Delete(int pos)
{
    Node *p,*q;
    int x=-1;
    if(pos==1)
    {
        p=first;
        x=first->data;
        first=first->next;
        delete p;
    }
    else
    {
        p=first;
        q=nullptr;
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
}

bool CheckWhetherSorted()
{
    int x=-32768;
    Node*p=first;
    while(p)
    {
        if(p->data < x)
        {
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}

void DeletingDuplicates()
{
    Node *p=first;
    Node *q=p->next;

    while(q)
    {
        if(p->data == q->data)
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
        else
        {
            p=q;
            q=q->next;
        }
    }
}

void ReverseElements()
{
    Node *p=first;
    int i=0;
    int A[10];
    while(p)
    {
        A[i]=p->data;
        i++;
        p=p->next;
    }
    p=first;
    i--;
    while(p)
    {
        p->data=A[i];
        i--;
        p=p->next;
    }
}

void ReverseLinks()
{
    Node *p=first;
    Node *q=nullptr;
    Node *r=nullptr;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void ReverseRecursion(Node *q,Node *p)
{
    if(p)
    {
        ReverseRecursion(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}

void concat(LinkedList l)
{
    Node *p=first;
    while(p->next)
    {
        p=p->next;
    }
    p->next=l.first;
}

void mergeLinkedList(LinkedList l)
{
    Node *tfirst;
    Node *last;
    if(first->data < l.first->data)
    {
        tfirst=last=first;
        first=first->next;
        last->next=nullptr;
    }
    else
    {
        tfirst=last=l.first;
        l.first=l.first->next;
        last->next=nullptr;
    }
    while(first && l.first)
    {
        if(first->data < l.first->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=nullptr;
        }
        else
        {
            last->next=l.first;
            last=l.first;
            l.first=l.first->next;
            last->next=nullptr;
        }
    }
    if(first)
    {
        last->next=first;
    }
    else if(l.first)
    {
        last->next=l.first;
    }
    first=tfirst;
}
bool isLoop()
{
    Node *p,*q;
    p=q=first;

    do
    {
        p=p->next;
        q=q->next;
        if(q)
            q=q->next;
    }while(p && q && p!=q);

    if(p==q)
        return true;
    else
        return false;
}
};
int main()
{
    cout << "Linked List :" << endl;
    LinkedList l1;
    l1.insertLast(8);
    l1.insertLast(5);
    l1.insertLast(15);
    l1.insertLast(20);
    l1.insertLast(38);
    l1.display(l1.first);
    cout<<endl;
    return 0;
}
