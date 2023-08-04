#include <iostream>

using namespace std;

int main()
{
    cout << "Finding Duplicates in Sorted Array using Hash Table" << endl;
    int A[]={3,6,8,8,10,12,15,15,15,20};
    int Alen=sizeof(A)/sizeof(int);
    int h=A[Alen-1];
    int l=A[0];
    int *H=new int[h];

    //Initializing Hash Table
    for(int i=0;i<=h;i++)
    {
        H[i]=0;
    }
    //Incrementing element in Hash Table
    for(int i=0;i<Alen;i++)
    {
        H[A[i]]++;
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
