#include <iostream>

using namespace std;

int main()
{
    cout << "Finding Pair with sum k in unsorted Array" << endl;
    int k=10;
    int A[]={6,3,8,10,16,7,5,2,9,14};
    int Alen=sizeof(A)/sizeof(int);

    for(int i=0;i<Alen-1;i++)
    {
        for(int j=i+1;j<Alen;j++)
        {
            if(A[i]+A[j]==k)
            {
                cout<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            }
        }
    }


    cout << "Finding Pair with sum k in unsorted Array using Hash Table" << endl;
    int h=16;
    int *H=new int[h];

    for(int i=0;i<h;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<Alen;i++)
    {

        if(H[k-A[i]]!=0 && k-A[i]>0)
        {
            cout<<A[i]<<" + "<<k-A[i]<<" = "<<k<<endl;
        }
        H[A[i]]++;
    }
    return 0;
}
