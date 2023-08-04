#include <iostream>

using namespace std;

int powSlower(int m,int n)
{
    if(n>0)
        return powSlower(m,n-1)*m;
    return 1;
}
int powFaster(int m,int n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return powFaster(m*m,n/2);
    else
        return m*powFaster(m*m,(n-1)/2);
}
int powIterative(int m,int n)
{
    for(int i=1;i<n;i++)
        m*=m;
    return m;
}
int main()
{
    cout << "Power function using Recursion" << endl;
    int r1=powIterative(2,2);
    int r2=powSlower(2,5);
    int r3=powFaster(2,9);
    cout<<r1<<endl;
    cout<<r2<<endl;
    cout<<r3<<endl;
    return 0;
}
