#include <iostream>

using namespace std;

int main()
{
    cout << "Finding Pairs with sum k in Sorted Array" << endl;
    int A[]={1,3,4,5,6,8,9,10,12,14};
    int k=10;
    int i=0;
    int j=(sizeof(A)/sizeof(int))-1;

    while(i<j)
    {
        if(A[i]+A[j]==k)
        {
            cout<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            i++;
            j--;
        }
        else if(A[i]+A[j]<k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}
