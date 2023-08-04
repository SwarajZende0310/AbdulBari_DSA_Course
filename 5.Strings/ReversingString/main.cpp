#include <iostream>

using namespace std;

int main()
{
    cout << "Reversing a String::Method 1 using different Array" << endl;
    char A[]="Python";
    int i=0;
    //Getting length of String
    for(i=0;A[i]!='\0';i++){}
    char B[i];
    i=i-1;
    int j;
    //Copying elements in reverse order
    for(j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    }
    B[j]='\0';
    cout<<B<<endl;

    cout<<"Reversing a String::Method 2 swapping extreme elements"<<endl;
    i=0;j=0;
    for(j=0;A[j]!='\0';j++){}

    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        char temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    cout<<A<<endl;
    return 0;
}
