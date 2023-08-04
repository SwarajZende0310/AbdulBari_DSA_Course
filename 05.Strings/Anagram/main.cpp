#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    //Method 1
    cout << "Checking for Anagram::Method 1" << endl;
    char A[]="decimal";
    char B[]="medical";

    int a=0;
    if(strlen(A)==strlen(B))
    {
        for(int i=0;A[i]!='\0';i++)
        {
            int f=0;
            for(int j=0;B[j]!='\0';j++)
            {
                if(A[i]==B[j])
                {
                    f++;
                }
            }
            if(f==0)
            {
                cout<<"Its is not a Anagram"<<endl;
                a++;
                break;
            }
        }
        if(a==0)
        {
            cout<<"It is Anagram "<<endl;
        }
    }

    //Method 2
    cout<<"Anagram::Using Hash Table"<<endl;
    char C[]="decimal";
    char D[]="medical";
    int i,H[26];
    for(i=0;C[i]!='\0';i++)
    {
        H[C[i]-97]++;
    }
    for(i=0;D[i]!='\0';i++)
    {
        H[D[i]-97]--;
        if(H[D[i]-97]<0)
        {
            cout<<"It is not an Anagram"<<endl;
            break;
        }
    }
    if(D[i]=='\0')
    {
        cout<<"Its a Anagram"<<endl;
    }
    return 0;
}
