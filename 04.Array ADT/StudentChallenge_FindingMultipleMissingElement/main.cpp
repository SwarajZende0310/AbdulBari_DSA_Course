#include <iostream>

using namespace std;

void MultipleMissing(int x[],int len)
{
    int l=x[0];
    int h=x[len-1];
    int diff=x[0]-0;
    for(int i=0;i<len;i++)
    {
        if((x[i]-i)!=diff)
        {
            while(diff<(x[i]-i))
            {
                cout<<"Missing Element is "<<i+diff<<endl;
                diff++;
            }
        }
    }
}
int main()
{
    cout << "Multiple Missing Element in Sorted Array:" << endl;
    int A[]={6,7,8,9,11,12,15,16,17,18,19};
    int Alen=sizeof(A)/sizeof(int);
    MultipleMissing(A,Alen);
    return 0;
}
