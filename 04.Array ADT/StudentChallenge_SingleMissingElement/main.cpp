#include <iostream>

using namespace std;

int SingleMissingCase1(int x[],int len)
{
    int n=x[len-1];
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum+=x[i];
    }
    int s=n*(n+1)/2;
    return s-sum;
}

int SingleMissingCase2(int x[],int len)
{
    int l=x[0];
    int h=x[len-1];
    int diff=x[0]-0;
    for(int i=0;i<len;i++)
    {
        if((x[i]-i)!=diff)
        {
            return diff+i;
        }
    }
}
int main()
{
    cout << "Finding Single Missing element in Sorted Array:" << endl;
    int A[]={1,2,3,4,5,6,8,9,10,11,12};
    int Alen=sizeof(A)/sizeof(int);
    int B[]={6,7,8,9,11,12,13,14,15,16,17};
    int Blen=sizeof(B)/sizeof(int);

    cout<<"Missing element from Array A is "<<SingleMissingCase1(A,Alen)<<endl;
    cout<<"Missing element from Array B is "<<SingleMissingCase2(B,Blen)<<endl;
    return 0;
}
