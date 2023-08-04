#include <iostream>

using namespace std;

int main()
{
    cout << "Upper case to Lower Case: " << endl;
    char A[]="WELCOME";
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90)
            A[i]+=32;
    }
    cout<<A<<endl;

    cout << "Lower case to Upper Case: " << endl;
    char B[]="welcome";
    for(int i=0;B[i]!='\0';i++)
    {
        if(B[i]>=97 && B[i]<=122)
            B[i]-=32;
    }
    cout<<B<<endl;

    cout << "Toggling Case: " << endl;
    char C[]="weLcOme";
    for(int i=0;C[i]!='\0';i++)
    {
        if(C[i]>=65 && C[i]<=90)
            C[i]+=32;
        else if(C[i]>=97 && C[i]<=122)
            C[i]-=32;
    }
    cout<<C<<endl;
    return 0;
}
