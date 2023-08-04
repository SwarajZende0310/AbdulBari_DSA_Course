#include <iostream>

using namespace std;

double TaylorRecursive(int x,int n)
{
    static double s=1;
    if(n==0)
        return s;
    s=1+x*s/n;
    return TaylorRecursive(x,n-1);
}
double TaylorIterative(int x,int n)
{
    double s=1;
    double num=1;
    double den=1;

    for(int i=1;i<=n;i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}
int main()
{
    cout << "Taylor Series Using Horners Rule" << endl;
    double r1=TaylorRecursive(1,10);
    double r2=TaylorIterative(1,10);
    cout<<r1<<endl<<r2<<endl;
    return 0;
}
