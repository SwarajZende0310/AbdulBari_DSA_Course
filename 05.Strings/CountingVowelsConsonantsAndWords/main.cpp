#include <iostream>

using namespace std;

int main()
{
    cout << "Counting Vowels Consonants and words in string:" << endl;
    string A="How are  you";
    int vcount=0,ccount=0,word=1;
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u' || A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U')
        {
            vcount++;
        }
        else if((A[i]>=65 && A[i]<=90)||(A[i]>=97 && A[i]<=122))
        {
            ccount++;
        }
        else if(A[i]==' ' && A[i-1]!=' ')
        {
            word++;
        }
    }
    cout<<"Number of Vowels are "<<vcount<<endl;
    cout<<"Number of Consonants are "<<ccount<<endl;
    cout<<"Number of words are "<<word<<endl;
    return 0;
}
