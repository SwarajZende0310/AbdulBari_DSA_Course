#include <iostream>

using namespace std;

int fact(int n)
{
    if(n>0)
        return fact(n-1)*n;
    return 1;
}
int C(int n,int r)
{
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(n-r);
    t3=fact(r);
    return t1/(t2*t3);
}

int CRecursive(int n,int r)
{
    if(r==0||n==r)
        return 1;
    return CRecursive(n-1,r-1)+CRecursive(n-1,r);
}
int main()
{
    cout << "nCr Using Recursion" << endl;
    int r=CRecursive(5,3);
    cout<<r<<endl;
    return 0;
}
