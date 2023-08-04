#include <iostream>

using namespace std;

int main()
{
    cout << "Comparing 2 Strings" << endl;
    char A[]="Painter";
    char B[]="Painting";
    //Changing case to lower case
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90)
            A[i]+=32;
    }

    for(int i=0;B[i]!='\0';i++)
    {
        if(B[i]>=65 && B[i]<=90)
            B[i]+=32;
    }

    int i,j;
    for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++)
    {
        if(A[i]!=B[j])
        {
            break;
        }
    }
    if(A[i]==B[j])
    {
        cout<<"Equal";
    }
    else if(A[i]<B[j])
    {
        cout<<A<<" comes before "<<B<<endl;
    }
    else
    {
        cout<<B<<" comes before "<<A<<endl;
    }
    return 0;
}
