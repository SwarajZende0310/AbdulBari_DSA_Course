#include <iostream>

using namespace std;

int F[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//Used for memoization
int fibslow(int n)
{
    if(n<=1)
        return n;
    return fibslow(n-2)+fibslow(n-1);
}

int fibmemo(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=fibmemo(n-2);
        if(F[n-1]==-1)
            F[n-1]=fibmemo(n-1);
        F[n]=F[n-2]+F[n-1];
        return F[n-2]+F[n-1];
    }
}

int Ifib(int n)
{
    int t0=0,t1=1,s=0;
    if(n<=1)
    {
        return n;
    }
    for(int i=2;i<=n;i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}
int main()
{
    cout << "Fibonacci Series using Memoization in Recursion" << endl;
    int r=fibmemo(7);
    int r1=Ifib(7);
    cout<<r<<endl<<r1<<endl;
    return 0;
}
