#include <iostream>

using namespace std;

int main()
{
    cout << "Essential Concepts: ARRAYS" << endl;
    int A[]={1,2,3,4,5};
    int arrsize=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<arrsize;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
