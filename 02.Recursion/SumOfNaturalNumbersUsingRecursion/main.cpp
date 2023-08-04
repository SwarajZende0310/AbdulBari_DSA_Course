#include <iostream>

using namespace std;

int naturalRecursiveSum(int n)
{
    if(n>0)
        return naturalRecursiveSum(n-1)+n;
    return 0;
}

int IterativeSum(int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s+=i;
    }
    return s;
}
int formulaeSum(int n)
{
    return n*(n+1)/2;
}
int main()
{
    cout << "Sum of Natural Numbers using Recursion" << endl;
    int sum=naturalRecursiveSum(10);
    int sum1=IterativeSum(10);
    int sum2=formulaeSum(10);

    cout<<sum<<endl<<sum1<<endl<<sum2<<endl;
    return 0;
}
