#include <iostream>
#include<math.h>
using namespace std;

class term
{
public:
    int exp;
    int coeff;
};

class Poly:public term
{
private:
    int n;
    term *t;
public:
    Poly(int n)
    {
        this->n=n;
        t=new term[n];
    }
    int evaluate(int x);
    Poly* operator+(Poly &p);
    friend istream & operator>>(istream &is,Poly &p);
    friend ostream & operator<<(ostream &os,Poly &p);
};

int Poly::evaluate(int x)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=t[i].coeff*pow(x,t[i].exp);
    }
    return sum;
}

Poly* Poly::operator+(Poly &p)
{
    int i=0,j=0,k=0;
    Poly *r=new Poly(n+p.n);

    while(i<n && j<p.n)
    {
        if(t[i].exp > p.t[j].exp)
        {
            r->t[k++]=t[i++];
        }
        else if(t[i].exp < p.t[j].exp)
        {
            r->t[k++]=p.t[j++];
        }
        else
        {
            r->t[k].exp=t[i].exp;
            r->t[k++].coeff=t[i++].coeff + p.t[j++].coeff;
        }
    }
    for(;i<n;i++)
    {
        r->t[k++]=t[i];
    }
    for(;j<p.n;j++)
    {
        r->t[k++]=p.t[j];
    }
    r->n=k;
    return r;
}

istream & operator>>(istream &is,Poly &p)
{
    cout<<"Enter Polynomial Terms: ";
    for(int i=0;i<p.n;i++)
    {
        cout<<"Enter term "<<i+1<<" ";
        cin>>p.t[i].coeff>>p.t[i].exp;
    }
    return is;
}

ostream & operator<<(ostream &os,Poly &p)
{
    for(int i=0;i<p.n;i++)
    {
        cout<<p.t[i].coeff<<"x"<<p.t[i].exp<<"+";
    }
    cout<<endl;
    return os;
}
int main()
{
    cout << "Polynomial Representation:" << endl;
    Poly p1(3);
    Poly p2(3);
    Poly*p3=p1+p2;
    cin>>p1;
    cin>>p2;

    cout<<"First Polynomial: "<<endl<<p1;
    cout<<"Second Polynomial: "<<endl<<p2;
    cout<<"Addition of Both Polynomial: "<<endl<<*p3;

    return 0;
}
