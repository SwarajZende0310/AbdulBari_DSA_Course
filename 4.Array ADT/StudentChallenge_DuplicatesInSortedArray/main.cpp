#include <iostream>

using namespace std;

int main()
{
    cout << "Finding Duplicates in Array:" << endl;
    int A[]={3,6,8,8,10,12,15,15,15,20};
    int Alen=sizeof(A)/sizeof(int);
    int LastDuplicate=0;
    for(int i=0;i<Alen-1;i++)
    {
        if(A[i]==A[i+1] && A[i]!=LastDuplicate)
        {
            cout<<"Duplicate element is "<<A[i]<<endl;
            LastDuplicate=A[i];
        }
    }

    cout<<endl<<"Counting frequency of Duplicates in Array:"<<endl;
    for(int i=0;i<Alen-1;i++)
    {
        if(A[i]==A[i+1])
        {
            int j=i+1;
            while(A[j]==A[i])
            {
                j++;
            }
            cout<<A[i]<<" is appearing "<<j-i<<" times in array"<<endl;
            i=j-1;
        }
    }
    return 0;
}
