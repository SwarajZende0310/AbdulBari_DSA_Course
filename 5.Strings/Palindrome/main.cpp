#include <iostream>

using namespace std;

int main()
{
    cout << "Palindrome::Method 1" << endl;
    char A[]="Nitin";
    int i,j;
    for(i=0;A[i]!='\0';i++){}
    char B[i];
    i=i-1;
    //Changing case to lower case
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90)
            A[i]+=32;
    }

    //Copying Reverse string
    for(j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    }

    for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++)
    {
        if(A[i]!=B[j])
        {
            break;
        }
    }
    if(A[i]==B[j])
    {
        cout<<A<<" is a Palindrome"<<endl;
    }
    else
    {
        cout<<A<<"Not a Palindrome"<<endl;
    }

    cout << "Palindrome::Method 1" << endl;
    char C[]="Swaraj";
    for(j=0;C[j]!='\0';j++){}

    j=j-1;

    for(i=0;i<j;i++,j--)
    {
        if(C[i]!=C[j])
        {
            break;
        }
    }
    if(C[i]==C[j])
    {
        cout<<C<<" is a Palindrome"<<endl;
    }
    else
    {
        cout<<C<<"is Not a Palindrome"<<endl;
    }
    return 0;
}
