#include <iostream>

using namespace std;

void fun1(int A[],int n)//'n' is number of elements it can access //'[]' can be replaced by '*'
//Array always passed by address
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}

int * fun2(int n)
{
    int *p;
    p=new int[5];
    return p;
}
int main()
{
    cout << "Essential Concepts:Array as Parameter" << endl;
    int arr[]={1,2,3,4,5};
    fun1(arr,5);
    cout<<endl;

    int *ptr;
    ptr=fun2(10);
    for(int i=0;i<10;i++)
    {
        ptr[i]=5*i;
    }
    for(int i=0;i<10;i++)
    {
        cout<<ptr[i]<<" ";
    }
    delete []ptr;
    return 0;
}
