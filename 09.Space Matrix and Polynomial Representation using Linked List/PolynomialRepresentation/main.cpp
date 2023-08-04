#include <iostream>
#include<math.h>
using namespace std;

class Term
{
    public:
    int coeff;
    int exp;
    Term* next;

    Term(){};
    Term(int c,int e)
    {
        coeff=c;
        exp=e;
        next=nullptr;
    }
};

class Poly:public Term
{
public:
    Term*last;
    Term*first;

    Poly(){};
    friend istream& operator>>(istream &is,Poly &p);
    friend ostream& operator<<(ostream &os,Poly &p);
    int evaluate(int x);
    Poly* operator+(Poly&p);
};

istream& operator>>(istream &is,Poly &p)
{
    cout<<"Enter Polynomial terms:"<<endl;
    int n,c,e,flag=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter term number "<<i+1<<endl;
        cin>>c>>e;
        if(flag==0)
        {
            p.first=p.last=new Term(c,e);
            flag++;
        }
        else
        {
            p.last->next=new Term(c,e);
            p.last=p.last->next;
        }
    }
    return is;
}

ostream& operator<<(ostream &os,Poly &p)
{
    Term *q=p.first;
    while(q)
    {
        cout<<q->coeff<<"x"<<q->exp<<"+";
        q=q->next;
    }
    cout<<endl;
    return os;
}

int Poly::evaluate(int x)
{
    int sum=0;
    Term *p=first;

    while(p)
    {
        sum+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return sum;
}
int main()
{
    cout << "Polynomial Representation" << endl;
    Poly p;
    cin>>p;
    cout<<p;
    cout<<p.evaluate(1)<<endl;
    return 0;
}
