#include <iostream>

using namespace std;

double pow(int m,int n);
double fact(int m);

double Taylor(int x,int n)
{
    if(n==0)
        return 1;
    return Taylor(x,n-1)+(pow(x,n)/fact(n));
}
double pow(int m,int n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return pow(m*m,n/2);
    else
        return m*pow(m*m,(n-1)/2);
}
double fact(int m)
{
    if(m==0)
        return 1;
    return m*fact(m-1);
}
//Sir s method more efficient
double Taylorefficient(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else
    {
        r=Taylorefficient(x,n-1);
        p*=x;
        f*=n;
        return r+p/f;
    }
}

int main()
{
    cout << "Taylor Series using Recursion" << endl;
    double r=Taylor(3,10);
    cout<<r<<endl;
    double r1=Tayloreffici ent(3,10);
    cout<<r1<<endl;
    return 0;
}
