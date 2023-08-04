#include <iostream>

using namespace std;

int main()
{
    int A[]={8,3,6,4,6,5,6,8,2,7};
    int Alen=sizeof(A)/sizeof(int);

    cout << "Finding Duplicates in Unsorted Array without using Hash Table" << endl;
    for(int i=0;i<Alen-1;i++)
    {
        int c=1;
        if(A[i]!=-1)
        {
            for(int j=i+1;j<Alen;j++)
            {
                if(A[i]==A[j])
                {
                    c++;
                    A[j]=-1;
                }
            }
        }
        if(c>1)
        {
            cout<<A[i]<<" is appearing "<<c<<" times"<<endl;
        }
    }
    cout<<endl;

    int B[]={8,3,6,4,6,5,6,8,2,7};
    int Blen=sizeof(B)/sizeof(int);
    cout << "Finding Duplicates in Unsorted Array using Hash Table" << endl;

    int h=8;
    int l=2;
    int *H=new int[h];

    //Initializing Hash Table
    for(int i=0;i<=h;i++)
    {
        H[i]=0;
    }
    //Incrementing element in Hash Table
    for(int i=0;i<Blen;i++)
    {
        H[B[i]]++;
    }
    //Printing Duplicate Element
    for(int i=l;i<=h;i++)
    {
        if(H[i]>1)
        {
            cout<<i<<" is appearing "<<H[i]<<" times"<<endl;
        }
    }
    return 0;
}
