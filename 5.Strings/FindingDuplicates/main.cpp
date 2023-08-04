#include <iostream>

using namespace std;

int main()
{
    cout << "Finding Duplicates::Method 1(Comparing with other letters)" << endl;
    char A[]="findings";
    for(int i=0;A[i+1]!='\0';i++)
    {
        int c=1;
        for(int j=i+1;A[j]!='\0';j++)
        {
            if(A[i]==A[j])
            {
                c++;
                A[j]=0;
            }
        }
        if(c>1)
        {
            cout<<A[i]<<" duplicates "<<c<<" times "<<endl;
        }
    }

    //Method 2
    cout<<"Finding Duplicates using Hash Table"<<endl;
    char C[]="Findings";
    int H[123];
    for(int i=0;i<123;i++)
    {
        H[i]=0;
    }
    for(int i=0;C[i]!='\0';i++)
    {
        H[C[i]]++;
    }

    for(int i=0;i<123;i++)
    {
        char c1;
        if(H[i]>1)
        {
            c1=i;
            cout<<c1<<" duplicates "<<H[i]<<" times "<<endl;
        }
    }

    //Method 3
    cout<<"Finding Duplicates using Bits"<<endl;
    char D[]="findings";
    int H1=0,x=1;

    for(int k=0;(D[k]!='\0');k++)
    {
        x=1;
        x=x<<D[k]-97;

        if((x&H1)>0)//Checking whether bit already 1
        {
            cout<<D[k]<<" is duplicate "<<endl;
        }
        else //Making bit as 1
        {
            H1=x|H1;
        }
    }
    return 0;
}
