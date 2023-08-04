#include <iostream>

using namespace std;

void perm1(char s[],int k)
{
    static int A[10]={0};
    static char Result[10];
    int i;
    if(s[k]=='\0')
    {
        Result[k]='\0';
        cout<<Result<<endl;
    }
    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Result[k]=s[i];
                A[i]=1;
                perm1(s,k+1);
                A[i]=0;
            }
        }
    }
}

void perm2(char s[],int l,int h)
{
    int i;
    if(l==h)
    {
        cout<<s<<endl;
    }
    else
    {
        for(i=0;i<=h;i++)
        {
            swap(s[l],s[i]);
            perm2(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}
int main()
{
    cout << "Permutation in String::Method 1" << endl;
    char string1[]="SWARAJ";
    perm1(string1,0);

    cout<<"Permutation in String::Method 2"<<endl;
    char string2[]="ABC";
    perm2(string2,0,2);
    return 0;
}
