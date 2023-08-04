#include <iostream>

using namespace std;

int factRecursive(int n)
{
    if(n>0)
        return factRecursive(n-1)*n;
    return 1;
}

int factIterative(int n)
{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}
int main()
{
    cout << "Factorial of number using recursion" << endl;
    int fact1=factRecursive(5);
    int fact2=factIterative(5);

    cout<<fact1<<endl<<fact2<<endl;
    return 0;
}
