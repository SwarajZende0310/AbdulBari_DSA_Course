#include <iostream>

using namespace std;

int main()
{
    cout << "Finding Missing elements in unsorted array:" << endl;
    int A[]={3,7,4,9,12,6,1,4,2,10};

    int l=1;
    int h=12;
    int n=10;

    int *H=new int[h];

    for(int i=0;i<n;i++)
    {
        H[A[i]]++;
    }

    for(int i=1;i<=h;i++)
    {
        if(H[i]==0)
        {
            cout<<"Missing Element is "<<i<<endl;
        }
    }
    return 0;
}
