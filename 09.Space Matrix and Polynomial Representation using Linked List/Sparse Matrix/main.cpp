#include <iostream>

using namespace std;

class Node
{
    public:
    int col;
    int val;
    Node * next;

    Node(int col,int val)
    {
        this->col=col;
        this->val=val;
        next=nullptr;
    }
};

int main() {
    cout << "Sparse Matrix:"<<endl;
    int m,n,flag=0;
    cout<<"Enter number of rows and columns: "<<endl;
    cin>>m>>n;
    Node*A[m];
    int val;
    Node *last;
    for(int i=0;i<m;i++)
    {
        flag=0;
        last=A[i];
        for(int j=0;j<n;j++)
        {
            cout<<"Enter value of "<<i<<" row and "<<j<<" column"<<endl;
            cin>>val;
            if(val==0)
            {
                continue;
            }
            else if(val!=0 && flag==0)
            {
                A[i]=last=new Node(j,val);
                //cout<<last->val<<endl;
                flag++;
            }
            else
            {
                last->next=new Node(j,val);
                last=last->next;
            }

        }
    }

    for(int i=0;i<m;i++)
    {
        Node *p=A[i];
        //cout<<"Entered loop when i="<<i<<endl;
        for(int j=0;j<n;j++)
        {
            //cout<<"Entered loop when j="<<j<<endl;
            if(p->col==j)
            {
                cout<<p->val<<" ";
                if(p->next)p=p->next;
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }


    int m1,n1,flag1=0;
    cout<<"Enter number of rows and columns: "<<endl;
    cin>>m1>>n1;
    Node*B[m1];
    for(int i=0;i<m1;i++)
    {
        flag=0;
        last=B[i];
        for(int j=0;j<n1;j++)
        {
            cout<<"Enter value of "<<i<<" row and "<<j<<" column"<<endl;
            cin>>val;
            if(val==0)
            {
                continue;
            }
            else if(val!=0 && flag==0)
            {
            B[i]=last=new Node(j,val);
                //cout<<last->val<<endl;
                flag1++;
            }
            else
            {
                last->next=new Node(j,val);
                last=last->next;
            }

        }
    }

    for(int i=0;i<m;i++)
    {
        Node *p=B[i];
        //cout<<"Entered loop when i="<<i<<endl;
        for(int j=0;j<n;j++)
        {
            //cout<<"Entered loop when j="<<j<<endl;
            if(p->col==j)
            {
                cout<<p->val<<" ";
                if(p->next)p=p->next;
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }

    cout<<"Adding"<<endl;

    for(int i=0;i<m;i++)
    {
        Node *p=A[i];
        Node *q=B[i];
        //cout<<"Entered loop when i="<<i<<endl;
        for(int j=0;j<n;j++)
        {
            //cout<<"Entered loop when j="<<j<<endl;
            if(p->col!=j && q->col!=j)
            {
                cout<<"0 ";
            }
            else if(p->col==q->col)
            {
                cout<<p->val+q->val<<" ";
                if(p->next){p=p->next;}
                if(q->next){q=q->next;}
            }
            else if(p->val==0)
            {
                cout<<q->val<<" ";
                if(q->next){q=q->next;}
            }
            else
            {
                cout<<p->val<<" ";
                if(p->next){p=p->next;}
            }
        }
        cout<<endl;
    }
    return 0;
}
